#include "social_network.h"

// User class definition.

User::User(std::string name) : name_(name), age_(0), height_(0), id_(-1), gender_(Gender::other), friends_{}, hobbies_{""} {}

void User::setAge(int age)
{
    age_ = age;
}

void User::setHeight(int height)
{
    height_ = height;
}

void User::setId(int id)
{
    id_ = id;
}

void User::setGender(Gender gender)
{
    gender_ = gender;
}

void User::setHobby(std::string hobby)
{
    hobbies_.insert(hobby);
}

void User::setFriend(int friendId)
{
    friends_.insert(friendId);
}

std::string User::getName() const
{
    return name_;
}

int User::getAge() const
{
    return age_;
}

int User::getHeight() const
{
    return height_;
}

int User::getId() const
{
    return id_;
}

Gender User::getGender() const
{
    return gender_;
}

std::set<std::string> User::getHobbies() const
{
    return hobbies_;
}

std::set<int> User::getFriends() const
{
    return friends_;
}

// SocialNetwork class definition
void SocialNetwork::addUser(const User &user)
{
    users[user.getId()] = user;
}

void SocialNetwork::deleteUser(int userId)
{
    users.erase(userId);
}

std::vector<User> SocialNetwork::searchUserByName(const std::string &name)
{
    return search([name](const User &user)
                  { return user.getName() == name; });
}
std::vector<User> SocialNetwork::searchUserByAge(int age)
{
    return search([age](const User &user)
                  { return user.getAge() == age; });
}
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
std::set<int> SocialNetwork::getFriendsOfUser(int userId)
{

    auto it = users.find(userId);
    if (it != users.end())
    {
        return it->second.getFriends();
    }
    return {};
}
