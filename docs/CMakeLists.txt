# add_custom_target(doc)
find_package(Doxygen)

if (DOXYGEN_FOUND)
    # set input and output files
    set(DOXYGEN_IN Doxyfile.in)
    set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile.out)

    # request to configure the file
    configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)
    message("Doxygen build started" ${CMAKE_CURRENT_BINARY_DIR})

    # Note: do not put "ALL" - this builds docs together with application EVERY TIME!
    add_custom_target( docs_doxygen
        COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        COMMENT "Generating API documentation with Doxygen"
        VERBATIM )
else (DOXYGEN_FOUND)
  message("Doxygen need to be installed to generate the doxygen documentation")
endif (DOXYGEN_FOUND)


# Sphinx setup
# find_program(SPHINX_EXECUTABLE sphinx-build)

# if(SPHINX_EXECUTABLE)
# set(SPHINX_SOURCE ${CMAKE_CURRENT_SOURCE_DIR})
# set(SPHINX_BUILD ${CMAKE_CURRENT_BINARY_DIR}/zat)

# add_custom_target(doc_sphinx
#     COMMAND ${SPHINX_EXECUTABLE} -b html ${SPHINX_SOURCE} ${SPHINX_BUILD}
#     COMMENT "Generating documentation with Sphinx"
#     # DEPENDS docs
#     VERBATIM
# )
# else()  
#     message(WARNING "Sphinx not found. Sphinx documentation will not be built.")
# endif()


# Combined target
add_custom_target(doc
    DEPENDS docs_doxygen #doc_sphinx
    COMMENT "Building full documentation"
)
