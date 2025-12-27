/**
 * @file test_social_network.cc
 * @brief Test file for the SocialNetwork class.
 */

#include "social_network.h"

/**
 * @brief Main function to test the SocialNetwork class.
 * 
 * This function creates a SocialNetwork, adds users, and performs various searches.
 * 
 * @return int Returns 0 on successful execution.
 */
int main()
{
  // Create a SocialNetwork instance
  SocialNetwork socialNetwork;

  // Create and configure user1
  User user1("Sriharsha");
  user1.setAge(25);
  user1.setHeight(180);
  user1.setId(1);
  user1.setGender(Gender::Male);
  user1.setHobby("Tennis");
  user1.setHobby("Jogging");
  user1.setFriend(2);
  user1.setFriend(3);
  user1.setFriend(4);

  // Create and configure user2
  User user2("Sahana");
  user2.setAge(22);
  user2.setHeight(170);
  user2.setId(2);
  user2.setGender(Gender::Female);
  user2.setHobby("Tennis");
  user2.setHobby("Jogging");
  user2.setFriend(6);

  // Add users to the social network
  socialNetwork.addUser(user1);
  socialNetwork.addUser(user2);

  // Search for user by name "Sriharsha"
  auto userName = socialNetwork.searchUserByName("Sriharsha");
  for (const auto &user : userName)
  {
    std::cout << "user name: " << user.getName() << "\n";
    std::cout << "User ID: " << user.getId() << "\n";
  }

  // Search for user by name "Sahana"
  auto userName1 = socialNetwork.searchUserByName("Sahana");
  for (const auto &user : userName1)
  {
    std::cout << "user name: " << user.getName() << "\n";
    std::cout << "User ID: " << user.getId() << "\n";
  }

  // Search for users with hobbies "Tennis" and "Jogging"
  auto hobbies = socialNetwork.searchUserByHobbies({"Tennis", "Jogging"});
  for (const auto &user : hobbies)
  {
    std::cout << "user with hobby tennis: " << user.getName() << "\n";
  }

  // Search for users with hobby "Jogging"
  auto hobbies1 = socialNetwork.searchUserByHobbies({"Jogging"});
  for (const auto &user : hobbies1)
  {
    std::cout << "user with hobby Jogging: " << user.getName() << "\n";
  }

  // Get friends of user1
  auto friends = socialNetwork.getFriendsOfUser(user1.getId());
  for (const auto &user : friends)
  {
    std::cout << "user with hobby Jogging: " << user << "\n";
  }
}