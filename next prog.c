#include <stdio.h>
struct User {
   int id;
    char name[100];
    int balance;
   };

void main() {

    struct User user1 = {"100", "kushi", "1200"};


    printf("User id: %d\n", user1.id);
    printf("User name: %s\n", user1.name);
    printf("User balance: %d\n", user1.balance);

    return 0;
}

