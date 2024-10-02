#include <iostream>
#include <string>

// Клас для зберігання даних про користувача
class User
{
public:
    User(const std::string& name, const std::string& email) : name(name), email(email) {}

    std::string getName() const { return name; }
    std::string getEmail() const { return email; }

private:
    std::string name;
    std::string email;
};

// Клас для роботи з базою даних (збереження користувача)
class UserRepository
{
public:
    void saveToDatabase(const User& user)
    {
        std::cout << "Збереження користувача в базу даних: " << user.getName() << " (" << user.getEmail() << ")\n";
    }
};

// Клас для надсилання електронних листів
class EmailService
{
public:
    void sendEmail(const User& user)
    {
        std::cout << "Надсилання електронного листа на адресу: " << user.getEmail() << "\n";
    }
};

int main()
{
    setlocale(LC_ALL, "Ukrainian");
    User user("Роман", "roma3x3@gmail.com");

    // Створюємо окремі класи для відповідальностей
    UserRepository userRepository;
    EmailService emailService;

    // Використання класів відповідно до їхніх відповідальностей
    userRepository.saveToDatabase(user);
    emailService.sendEmail(user);

    return 0;
}
