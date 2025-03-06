#include <stdio.h>

// Define the structure for a user
struct User {
    char name[50];
    int age;
    char email[100];
};

int main() {
    // Create an array of users and assign values
    struct User users[3] = {
        {"John Doe", 25, "johndoe@example.com"},
        {"Jane Smith", 30, "janesmith@example.com"},
        {"Alice Johnson", 22, "alicejohnson@example.com"}
    };

    // Loop through the array and print user details
    for (int i = 0; i < 3; i++) {
        printf("User %d:\n", i+1);
        printf("Name: %s\n", users[i].name);
        printf("Age: %d\n", users[i].age);
        printf("Email: %s\n\n", users[i].email);
    }

    return 0;
}

