/* In this exercise we want to design a simple social network.
 * We have users which have a name, an age, a height (in cm), a set of hobbies,
 * an entry whether they are male or female, an internal ID and a set of friends.
 * A user doesn't have to provide all information except the name. The name always has to be provided. (think about how to design this)
 * 
 * Our SocialNetwork should provide us with the possibility to add and delete users
 * from the network. It should also allow us to search users by name, age, id or hobbies. 
 * Eg.:
 *      searchUserByName("Jochen");
 *      searchUserByAge(36);
 *      searchUserByHobbies({"Jogging", "Football", "Tennis"}); //Returns alls users which have the hobbies jogging, footbal AND tennis.
 * Additionally we want to receive all the friends a particular user has. But we only want to receive the set of ID's of those users (friends).
      ... getFriendsOfUser(...)
 *
 * Neither the names of the users have to be unique (e.g. we can have multiple Klaus in the network) nor any other attribute.
 * Only the id of every user has to be unique in the whole network.
 * 
 * The skeleton code below can be used as a starting point but doesn't have to.
 * The comments "fill in" are placeholders where you definitely have to put in some code when 
 * you use this skeleton code. But this doesn't mean that you shouldn't or can't put code anywhere else.
 *
 * Also write some simple unit tests to show how you would test the functionality of the Network.
 * Don't use any testing framework. Simple if-statements are sufficient for this exercise.
 *
 * Hint: Think about performance versus memory tradeoffs in your design, so you can give good 
 *       reasons for your decision. 
 */

#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <functional>
#include <algorithm>
#include <set>
#include <vector>


enum class Gender {Male, Female, other};

class User
{
	/*fill in*/
	public:
        User() = default;
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
 
class SocialNetwork
{
public:
	void addUser(const User& user);
    void deleteUser(int userId);
    std::vector<User> searchUserByName(const std::string& name);
    std::vector<User> searchUserByAge(int age);
    std::vector<User> searchUserByHobbies(const std::set<std::string>& hobbies);
    std::set<int> getFriendsOfUser(int userId);

	
private:

	std::vector<User> search(std::function<bool(const User&)> function) {
		std::vector<User> result;
		for(const auto& val : users) {
			if(function(val.second)){
				result.push_back(val.second);
			}
		}
		return result;
	}

	std::unordered_map<int, User> users;
};
