#include <stdio.h>
#include <string.h>

#define MAX_USERS 100

// User structure
typedef struct {
    int id;
    char name[50];
    double balance;
} User;

User users[MAX_USERS];
int userCount = 0;

// Function to create a new user
void createUser(int id, const char *name, double balance) {
    if (userCount >= MAX_USERS) {
        printf("User limit reached.\n");
        return;
    }
    users[userCount].id = id;
    strcpy(users[userCount].name, name);
    users[userCount].balance = balance;
    userCount++;
    printf("User created successfully.\n");
}

// Function to update user details
void updateUser(int id, const char *newName, double newBalance) {
    for (int i = 0; i < userCount; i++) {
        if (users[i].id == id) {
            strcpy(users[i].name, newName);
            users[i].balance = newBalance;
            printf("User updated successfully.\n");
            return;
        }
    }
    printf("User not found.\n");
}

// Function to delete a user
void deleteUser(int id) {
    for (int i = 0; i < userCount; i++) {
        if (users[i].id == id) {
            // Shift remaining users to remove the deleted user
            for (int j = i; j < userCount - 1; j++) {
                users[j] = users[j + 1];
            }
            userCount--;
            printf("User deleted successfully.\n");
            return;
        }
    }
    printf("User not found.\n");
}

// Function to credit money to a user's account
void creditMoney(int id, double amount) {
    for (int i = 0; i < userCount; i++) {
        if (users[i].id == id) {
            users[i].balance += amount;
            printf("Credited %.2f to user %d. New balance: %.2f\n", amount, id, users[i].balance);
            return;
        }
    }
    printf("User not found.\n");
}

// Function to debit money from a user's account
void debitMoney(int id, double amount) {
    for (int i = 0; i < userCount; i++) {
        if (users[i].id == id) {
            if (users[i].balance >= amount) {
                users[i].balance -= amount;
                printf("Debited %.2f from user %d. New balance: %.2f\n", amount, id, users[i].balance);
            } else {
                printf("Insufficient balance.\n");
            }
            return;
        }
    }
    printf("User not found.\n");
}

// Function to transfer money between two users
void transferMoney(int fromId, int toId, double amount) {
    User *fromUser = NULL;
    User *toUser = NULL;

    for (int i = 0; i < userCount; i++) {
        if (users[i].id == fromId) {
            fromUser = &users[i];
        }
        if (users[i].id == toId) {
            toUser = &users[i];
        }
    }

    if (fromUser && toUser) {
        if (fromUser->balance >= amount) {
            fromUser->balance -= amount;
            toUser->balance += amount;
            printf("Transferred %.2f from user %d to user %d. New balance of user %d: %.2f, user %d: %.2f\n",
                   amount, fromId, toId, fromId, fromUser->balance, toId, toUser->balance);
        } else {
            printf("Insufficient balance to transfer.\n");
        }
    } else {
        printf("User(s) not found.\n");
    }
}

int main() {
    // Example: Creating some users
    createUser(1, "Alice", 500);
    createUser(2, "Bob", 300);

    // Operations
    creditMoney(1, 200);
    debitMoney(2, 50);
    transferMoney(1, 2, 100);

    // Update a user
    updateUser(1, "Alice Cooper", 800);

    // Delete a user
    deleteUser(2);

    return 0;
}

