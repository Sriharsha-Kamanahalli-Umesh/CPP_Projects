#include "social_network.h"

int main() {

	SocialNetwork socialNetwork;

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

	User user2("Sahana");
	user2.setAge(22);
	user2.setHeight(170);
	user2.setId(2);
	user2.setGender(Gender::Female);
	user2.setHobby("Tennis");
	user2.setHobby("Jogging");
	user2.setFriend(6);

	socialNetwork.addUser(user1);
	socialNetwork.addUser(user2);

	auto userName = socialNetwork.searchUserByName("Sriharsha");
	for(const auto& user : userName) {
		std::cout<<"user name: "<< user.getName() <<"\n";
		std::cout<<"User ID: "<< user.getId() <<"\n";
	}

	auto userName1 = socialNetwork.searchUserByName("Sahana");
	for(const auto& user : userName1) {
		std::cout<<"user name: "<< user.getName() <<"\n";
		std::cout<<"User ID: "<< user.getId() <<"\n";
	}

	auto hobbies = socialNetwork.searchUserByHobbies({"Tennis", "Jogging"});
	for(const auto& user : hobbies) {
		std::cout<<"user with hobby tesnnis: "<< user.getName() <<"\n";
	}

	auto hobbies1 = socialNetwork.searchUserByHobbies({"Jogging"});
	for(const auto& user : hobbies1) {
		std::cout<<"user with hobby Jogging: "<< user.getName() <<"\n";
	}

	auto friends = socialNetwork.getFriendsOfUser(user1.getId());
	for(const auto& user : friends) {
		std::cout<<"user with hobby Jogging: "<< user <<"\n";
	}
	

}