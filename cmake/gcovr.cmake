# -------------- set Report source ----------------------------
# TODO: this need to be changed to support individual reporting of components
set(Report_Source_CPP_Project
    ${CMAKE_SOURCE_DIR}/
    COMMAND echo " create GCOV Report"
)


# ---------set thresholds which leads to a failing job --------
set(FAIL_UNDER_LINE_COVR_THRESHOLD_PERC      99.8)
set(FAIL_UNDER_LINE_COVR_THRESHOLD_S2S_PERC      98)
set(FAIL_UNDER_LINE_COVR_THRESHOLD_MS_REG_PERC      87)
set(FAIL_UNDER_BRANCH_COVR_THRESHOLD_PERC    67)
set(FAIL_UNDER_BRANCH_COVR_THRESHOLD_S2S_PERC    22)
set(FAIL_UNDER_BRANCH_COVR_THRESHOLD_MS_REG_PERC    59)

# ------------- set Report output -----------------------------
set(Report_Output_Folder_CPP_Project ${CMAKE_SOURCE_DIR}/reports/gcovr)

add_custom_target(gcovr
    # COMMAND ${CMAKE_MAKE_PROGRAM} test
    # WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    )

add_custom_command(TARGET gcovr
    COMMAND ${CMAKE_COMMAND} -E make_directory ${Report_Output_Folder_CPP_Project}/html ${Report_Output_Folder_CPP_Project}/json
    COMMAND echo "=================== create GCOV Report ===================="
    COMMAND gcovr -r ${Report_Source_CPP_Project} ${CMAKE_BINARY_DIR} -s
        --exclude '.*/test/'
		--exclude '.*/main.cpp'
        --fail-under-line ${FAIL_UNDER_LINE_COVR_THRESHOLD_PERC}
        --fail-under-branch ${FAIL_UNDER_BRANCH_COVR_THRESHOLD_PERC}
        --txt
        --html ${Report_Output_Folder_MS_ARACOM}/html/report.html --html-details
        --json ${Report_Output_Folder_MS_ARACOM}/json/report.json --json-pretty
        --json-summary ${Report_Output_Folder_MS_ARACOM}/json/report_summary.json --json-summary-pretty
    )
