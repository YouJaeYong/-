#include<iostream>
#include<vector>
#include<memory>//smart_ptr 사용

using namespace std;

class User;
class Guild;
typedef shared_ptr<Guild> GuildShdPtr;
typedef shared_ptr<User> UserShdPtr;
class User
{
public://원래 이러면 안됨
	string id;
	GuildShdPtr myGuild;
	User(string ID) : id(ID)
	{
		cout << "User Class : "<<id <<" Construction" << endl;
	}

	~User()
	{
		cout << "User Class : " << id << " Destruction" << endl;
	}
	void setGuild(GuildShdPtr guild)
	{
		myGuild = guild;
	}
};

class Guild
{
	string guildName;

	vector<UserShdPtr> GuildMembers;
public:
	Guild(string name) : guildName(name)
	{
		cout << "Guild Class : " << guildName << " Construction" << endl;
	}


	~Guild()
	{
		GuildMembers.clear();
	}

	void AddGuildMember(const UserShdPtr& user)
	{
		GuildMembers.push_back(user);
	}


};



string GetUserID(shared_ptr<User> userPtr)
{
	cout<<"count 3 : "<<userPtr.use_count() <<endl;
	return userPtr.get()->id;
}
int main()
{

	shared_ptr<User> userPtr(new User("FirstSharedPtr"));
	cout << "count 1 : " << userPtr.use_count() << endl;
	shared_ptr<User> userPtr2 = userPtr;
	cout << "count 2 : " << userPtr.use_count() << endl;
	string s =GetUserID(userPtr2);//복사, 일부러 call by value
	cout << "count 4 : " << userPtr.use_count() << endl;


	User* SharedPtrGet = userPtr.get();
	
	cout <<"get() method test : " <<SharedPtrGet->id  << endl;


	cout << "******Circular Reference******" << endl;

	GuildShdPtr my_Guild( new Guild("JaeyongGuild"));

	for (int i = 0; i < 3; ++i)
	{

		UserShdPtr user(new User("Dummy"));
		my_Guild->AddGuildMember(user);
		user->setGuild(my_Guild);
		cout << "RefCount - AddGuild : " << my_Guild.use_count() << endl;
	}
	cout << "RefCount - After_Scope_Ended(circular ref) : " << my_Guild.use_count() << endl; //유저는 스코프 끝나면서 소멸했는데, my_Guild를 참조하는 카운트는 여전히 유지됨.	


	cout << "위의 로직을 weak_ptr을 활용해 구현" << endl;

	GuildShdPtr my_Guild_weak(new Guild("WeakPtrGuild"));

	for (int i = 0; i < 3; ++i)
	{

		UserShdPtr user(new User("weak_Dummy"));

		weak_ptr<User> weak_user = user; //shared ptr를 weak ptr에 대입

		UserShdPtr lock_check = weak_user.lock();
		if (lock_check)
		{
			my_Guild_weak->AddGuildMember(lock_check);

			user->setGuild(my_Guild);
		}
		
		cout << "RefCount - AddGuild : " << my_Guild_weak.use_count() << endl;
	}

}