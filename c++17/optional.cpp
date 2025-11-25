// std::optional is a feature introduced in C++17.
// std::optional represents an object that may or may not contain a value.
// It provides a way to express optional values without using pointers or special sentinel values.
// Key Characteristics:
    // 1. Contains Value or Not: An std::optional object can either contain a value of a specified type or be empty (no value).
    // 2. Type Safety: The type of the contained value is known at compile-time, providing type safety.
    // 3. Easy to Use: std::optional provides a simple interface to check for the presence of a value and to access the value if it exists.
// ✅ Why Use std::optional?
    // 1. Clear Intent: Using std::optional makes it clear that a value may be absent, improving code readability.
    // 2. Avoid Null Pointers: It helps avoid the use of null pointers or special sentinel values to represent the absence of a value.
    // 3. Simplified Error Handling: It can simplify error handling by allowing functions to return an optional value instead of throwing exceptions or using error codes.
// When to Use std::optional?
// Use std::optional when:
    // 1. A function may not always be able to return a valid value.
    // 2. You want to represent optional configuration parameters.
    // 3. You want to avoid using pointers for optional values.


// #include <iostream>
// #include <optional>
// #include <string>

// std::optional<std::string> findUsernameById(int id) {
//     if (id == 1) {
//         return "Alice";
//     } else if (id == 2) {
//         return "Bob";
//     } else {
//         return std::nullopt; // No value
//     }
// }

// int main() {
//     int userId = 2;
//     std::optional<std::string> username = findUsernameById(userId);

//     if (username) {
//         std::cout << "Username found: " << *username << std::endl;
//     } else {
//         std::cout << "No username found for ID: " << userId << std::endl;
//     }

//     // Using value_or to provide a default value
//     std::string defaultUsername = username.value_or("Guest");
//     std::cout << "Welcome, " << defaultUsername << "!" << std::endl;

//     return 0;
// }


#include <iostream>
#include <optional>
#include <string>
#include <map>

class ConfigLoader {
    std::map<std::string, std::string> configData;

public:
    ConfigLoader() {
        // Simulate loading from a file
        configData["timeout"] = "30";
        configData["logPath"] = "/var/log/app.log";
        // Note: "maxThreads" is not set
    }

    std::optional<std::string> getValue(const std::string& key) const {
        auto it = configData.find(key);
        if (it != configData.end()) {
            return it->second;
        }
        return std::nullopt;
    }
};

int main() {
    ConfigLoader loader;

    auto timeout = loader.getValue("timeout");
    auto logPath = loader.getValue("logPath");
    auto maxThreads = loader.getValue("maxThreads"); // not set

    
    if (timeout) {
        std::cout << "Timeout: " << *timeout << "\n";
        timeout.reset(); // clears the value
        if (!timeout.has_value()) {
            std::cout << "Timeout is now empty\n";
        }
    }


    if (logPath) {
        std::cout << "Log Path: " << logPath.value() << "\n";
    }

    if (maxThreads.has_value()) {
        std::cout << "Max Threads: " << *maxThreads << "\n";
    } else {
        std::cout << "Max Threads not " << maxThreads.value_or("configured.") << "\n";
    }

    return 0;
}

// #include <iostream>
// #include <optional>
// #include <string>

// class UserProfile {
//     std::string username;
//     std::optional<std::string> nickname;
//     std::optional<std::string> email;
//     std::optional<std::string> phone;

// public:
//     UserProfile(std::string uname) : username(uname) {}

//     void setNickname(const std::string& nick) { nickname = nick; }
//     void setEmail(const std::string& mail) { email = mail; }
//     void setPhone(const std::string& ph) { phone = ph; }

//     void displayProfile() const {
//         std::cout << "Username: " << username << "\n";
        
//         // Normal way
//         if (nickname) {
//             std::cout << "Nickname: " << *nickname << "\n";
//         } else {
//             std::cout << "Nickname: [not set]\n";
//         }
//         // with std::optional
//         std::cout << "Nickname: " << nickname.value_or("[not set]") << "\n";
//         std::cout << "Email: " << email.value_or("[not set]") << "\n";
//         std::cout << "Phone: " << phone.value_or("[not set]") << "\n";

//         if(nickname.has_value()) {
//             std::cout << nickname.value() << "\n";
//         }
//     }
// };

// int main() {
//     UserProfile user("Sriharsha");

//     // user.setNickname("");
//     user.setEmail("sri@example.com");
//     // user.setNickname("Harsha"); // not set
//     // user.setPhone("9876543210");

//     user.displayProfile();

//     return 0;
// }
