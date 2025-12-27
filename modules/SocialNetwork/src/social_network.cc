/**
 * @file social_network.cc
 * @brief Implementation file for the SocialNetwork class.
 */

#include "social_network.h"

// User class definition.

/**
 * @brief Constructs a new User object with the given name.
 * 
 * @param name The name of the user.
 */
User::User(std::string name) : name_(name), age_(0), height_(0), id_(-1), gender_(Gender::other), friends_{}, hobbies_{""} {}

/**
 * @brief Sets the age of the user.
 * 
 * @param age The age of the user.
 */
void User::setAge(int age)
{
    age_ = age;
}

/**
 * @brief Sets the height of the user.
 * 
 * @param height The height of the user in cm.
 */
void User::setHeight(int height)
{
    height_ = height;
}

/**
 * @brief Sets the ID of the user.
 * 
 * @param id The unique ID of the user.
 */
void User::setId(int id)
{
    id_ = id;
}

/**
 * @brief Sets the gender of the user.
 * 
 * @param gender The gender of the user.
 */
void User::setGender(Gender gender)
{
    gender_ = gender;
}

/**
 * @brief Adds a hobby to the user's set of hobbies.
 * 
 * @param hobby The hobby to be added.
 */
void User::setHobby(std::string hobby)
{
    hobbies_.insert(hobby);
}

/**
 * @brief Adds a friend to the user's set of friends.
 * 
 * @param friendId The ID of the friend to be added.
 */
void User::setFriend(int friendId)
{
    friends_.insert(friendId);
}

/**
 * @brief Gets the name of the user.
 * 
 * @return std::string The name of the user.
 */
std::string User::getName() const
{
    return name_;
}

/**
 * @brief Gets the age of the user.
 * 
 * @return int The age of the user.
 */
int User::getAge() const
{
    return age_;
}

/**
 * @brief Gets the height of the user.
 * 
 * @return int The height of the user in cm.
 */
int User::getHeight() const
{
    return height_;
}

/**
 * @brief Gets the ID of the user.
 * 
 * @return int The unique ID of the user.
 */
int User::getId() const
{
    return id_;
}

/**
 * @brief Gets the gender of the user.
 * 
 * @return Gender The gender of the user.
 */
Gender User::getGender() const
{
    return gender_;
}

/**
 * @brief Gets the set of hobbies of the user.
 * 
 * @return std::set<std::string> The set of hobbies of the user.
 */
std::set<std::string> User::getHobbies() const
{
    return hobbies_;
}

/**
 * @brief Gets the set of friends of the user.
 * 
 * @return std::set<int> The set of friend IDs of the user.
 */
std::set<int> User::getFriends() const
{
    return friends_;
}

// SocialNetwork class definition

/**
 * @brief Adds a user to the social network.
 * 
 * @param user The user to be added.
 */
void SocialNetwork::addUser(const User &user)
{
    users[user.getId()] = user;
}

/**
 * @brief Deletes a user from the social network.
 * 
 * @param userId The ID of the user to be deleted.
 */
void SocialNetwork::deleteUser(int userId)
{
    users.erase(userId);
}

/**
 * @brief Searches for users by name.
 * 
 * @param name The name to search for.
 * @return std::vector<User> A vector of users with the given name.
 */
std::vector<User> SocialNetwork::searchUserByName(const std::string &name)
{
    return search([name](const User &user)
                  { return user.getName() == name; });
}

/**
 * @brief Searches for users by age.
 * 
 * @param age The age to search for.
 * @return std::vector<User> A vector of users with the given age.
 */
std::vector<User> SocialNetwork::searchUserByAge(int age)
{
    return search([age](const User &user)
                  { return user.getAge() == age; });
}

/**
 * @brief Searches for users by hobbies.
 * 
 * @param hobbies The set of hobbies to search for.
 * @return std::vector<User> A vector of users with the given hobbies.
 */
std::vector<User> SocialNetwork::searchUserByHobbies(const std::set<std::string> &hobbies)
{
    return search([hobbies](const User &user)
                  {
        for(const auto& hobby : hobbies) {
            if(user.getHobbies().find(hobby) == user.getHobbies().end()) {
                return false;
            }
        }
        return true; });
}

/**
 * @brief Gets the set of friends of a user.
 * 
 * @param userId The ID of the user.
 * @return std::set<int> The set of friend IDs of the user.
 */
std::set<int> SocialNetwork::getFriendsOfUser(int userId)
{
    auto it = users.find(userId);
    if (it != users.end())
    {
        return it->second.getFriends();
    }
    return {};
}
