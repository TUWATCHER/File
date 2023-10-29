#include <filesystem>
#include "user.h"
#include "message.h"

using fstream = std::fstream;
namespace fsystem = std::filesystem;

void UserLog(const std::string& filename, User& user);
void MessageLog(const std::string& filename, Message& msg);

int main()
{
    std::string filename = "userlog.txt";
    User user1{"User1", "usr1", "12345"};
    UserLog(filename, user1);
    User user2{"User2", "usr2", "123"};
    UserLog(filename, user2);

    std::string message_file = "messagelog.txt";
    Message msg1("HellO!", "usr1", "usr2");
    MessageLog(message_file, msg1);
    return 0;
}

void UserLog(const std::string &filename, User &user)
{
    fstream user_file = fstream(filename, std::ios_base::in | std::ios_base::out);
	if (!user_file)
    {
            std::cout << "File not found! Creating a new one!\n";
		    user_file = fstream(filename, std::ios_base::in | std::ios_base::out | std::ios_base::trunc);
    }	
	if (user_file)
    {
        std::filesystem::permissions(
        filename,
        fsystem::perms::set_uid | fsystem::perms::owner_all,
        fsystem::perm_options::remove);

        user_file.seekp(0, std::ios_base::end);		
		user_file << user << endl;
        
		user_file.seekg(0, ios_base::beg);        
		user_file >> user;
		std::cout << user << endl;

        user_file.close();
	}
	else
	{
		std::cout << "Could not open file " << filename << '\n';
    }
}

void MessageLog(const std::string &filename, Message &msg)
{
    fstream message_file = fstream(filename, std::ios_base::in | std::ios_base::out);
	if (!message_file)
    {
            std::cout << "File not found! Creating a new one!\n";
		    message_file = fstream(filename, std::ios_base::in | std::ios_base::out | std::ios_base::trunc);
    }	
	if (message_file)
    {
        std::filesystem::permissions(
        filename,
        fsystem::perms::set_uid | fsystem::perms::owner_all,
        fsystem::perm_options::remove);

        message_file.seekp(0, std::ios_base::end);		
		message_file << msg << endl;
        
		message_file.seekg(0, ios_base::beg);        
		message_file >> msg;
		std::cout << msg << endl;

        message_file.close();
	}
	else
	{
		std::cout << "Could not open file " << filename << '\n';
    }
}
