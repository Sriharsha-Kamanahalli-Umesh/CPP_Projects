/**
 * @file social_network.h
 * @brief Header file defining the User and SocialNetwork classes.
 */

#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <functional>
#include <algorithm>
#include <set>
#include <vector>

/**
 * @brief Enumeration for gender.
 */
enum class Gender
{
    Male,
    Female,
    other
};

/**
 * @brief Class representing a user in the social network.
 */
class User
{
public:
    User() = default;
    /**
     * @brief Constructs a new User object with the given name.
     * 
     * @param name The name of the user.
     */
    User(std::string name);

    void setAge(int age);
    void setHeight(int height);
    void setId(int id);
    void setGender(Gender gender);
    void setHobby(std::string hobby);
    void setFriend(int friendId);

    std::string getName() const;
    int getAge() const;
    int getHeight() const;
    int getId() const;
    Gender getGender() const;
    std::set<std::string> getHobbies() const;
    std::set<int> getFriends() const;

private:
    std::string name_;
    int age_;
    int height_;
    int id_;
    Gender gender_;
    std::set<std::string> hobbies_;
    std::set<int> friends_;
};

/**
 * @brief Class representing a social network.
 */
class SocialNetwork
{
public:
    void addUser(const User &user);
    void deleteUser(int userId);
    std::vector<User> searchUserByName(const std::string &name);
    std::vector<User> searchUserByAge(int age);
    std::vector<User> searchUserByHobbies(const std::set<std::string> &hobbies);
    std::set<int> getFriendsOfUser(int userId);

private:
    std::vector<User> search(std::function<bool(const User &)> function)
    {
        std::vector<User> result;
        for (const auto &val : users)
        {
            if (function(val.second))
            {
                result.push_back(val.second);
            }
        }
        return result;
    }

    std::unordered_map<int, User> users;
};
