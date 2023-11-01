#include <filesystem>
#include "user.h"
#include "message.h"

using fstream = std::fstream;
namespace fsystem = std::filesystem;

template <typename T1> void Log(const std::string& filename, T1& object);

int main()
{
    std::string filename = "userlog.txt";
    User user1{"User3", "usr1", "12345"};
    Log(filename, user1);
    User user2{"User5", "usr2", "123"};
    Log(filename, user2);

    std::string message_file = "messagelog.txt";
    Message msg1("HellO!", "usr3", "usr5");
    Log(message_file, msg1);
    return 0;
}

template <typename T1> 
void Log(const std::string &filename, T1 &object)
{
    fstream log_file = fstream(filename, std::ios_base::in | std::ios_base::out);
	if (!log_file)
    {
            std::cout << "File not found! Creating a new one!\n";
		    log_file = fstream(filename, std::ios_base::in | std::ios_base::out | std::ios_base::trunc);
    }	
	if (log_file)
    {
        std::filesystem::permissions(
        filename,
        fsystem::perms::set_uid | fsystem::perms::owner_all,
        fsystem::perm_options::remove);

        log_file.seekp(0, std::ios_base::end);		
		log_file << object << endl;
        
		log_file.seekg(0, ios_base::beg);        
		log_file >> object;
		std::cout << object << endl;

        log_file.close();
	}
	else
	{
		std::cout << "Could not open file " << filename << '\n';
    }
}
