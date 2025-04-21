# ATM System Project - Complete Explanation

## Table of Contents
1. [Project Architecture and Setup](#part-1-project-architecture-and-setup)
2. [Core Data Structures](#part-2-core-data-structures)
3. [Authentication System](#part-3-authentication-system)
4. [Account Management](#part-4-account-management)
5. [Transaction Processing](#part-5-transaction-processing)
6. [Data Storage](#part-6-data-storage)
7. [Security Features](#part-7-security-features)
8. [Interest Calculation](#part-8-interest-calculation)
9. [Error Handling](#part-9-error-handling)
10. [User Interface](#part-10-user-interface)
11. [Detailed Function Explanations](#part-11-detailed-function-explanations)
12. [Detailed Function Analysis](#part-12-detailed-function-analysis)

# Part 1: Project Architecture and Setup

## 1. Project Structure
```
project/
├── src/                    # Source code directory
│   ├── main.c             # Main program entry point
│   ├── auth.c             # Authentication functions
│   ├── system.c           # Core banking operations
│   └── header.h           # Header file with declarations
├── data/                  # Data storage directory
│   ├── users.txt          # User credentials storage
│   └── records.txt        # Account records storage
├── Makefile              # Build configuration
└── README.md             # Project documentation
```

## 2. Build System (Makefile)
```makefile
CC = gcc                    # Compiler
CFLAGS = -Wall -Wextra -g  # Compiler flags
SRC_DIR = src              # Source directory
OBJ_DIR = obj              # Object files directory
BIN_DIR = bin              # Binary output directory
```

The Makefile provides several commands:
- `make all`: Builds the project
- `make clean`: Cleans build files
- `make run`: Builds and runs the program
- `make help`: Shows available commands

# Part 2: Core Data Structures

## 1. User Structure
```c
struct User {
    int id;                                    // Unique user identifier
    char name[MAX_USERNAME_SIZE];             // Username
    char password[MAX_PASSWORD_SIZE];         // User password
};
```

## 2. Record Structure (Account Information)
```c
struct Record {
    int id;                                    // Record identifier
    int userId;                                // Owner's user ID
    char name[MAX_USERNAME_SIZE];             // Owner's username
    char country[MAX_COUNTRY_SIZE];           // Account country
    int phone;                                // Contact number
    char accountType[MAX_TRANSACTION_TYPE_SIZE]; // Account type
    int accountNbr;                           // Account number
    double amount;                            // Account balance
    struct Date deposit;                      // Deposit date
    struct Date withdraw;                     // Withdrawal date
};
```

# Part 3: Authentication System

## 1. Initial Menu (initMenu)
```c
void initMenu(struct User *u) {
    // Displays login/register options
    // Handles user choice
    // Manages authentication flow
}
```

Purpose:
- Entry point for user interaction
- Provides options for login/register/exit
- Initializes user session

## 2. Login Process (loginMenu)
```c
void loginMenu(char a[], char pass[]) {
    // Handles username input
    // Masks password input
    // Validates credentials
}
```

Features:
- Secure password input (masked)
- Username validation
- Password verification

## 3. Registration Process (registerMenu)
```c
void registerMenu(char a[], char pass[]) {
    // Handles new user registration
    // Validates username uniqueness
    // Creates user account
}
```

Features:
- Username uniqueness check
- Password creation
- User account creation

# Part 4: Account Management

## 1. Account Creation
```c
void createNewAccount(struct User u) {
    // Creates new bank account
    // Handles different account types
    // Stores account information
}
```

Account Types:
- Savings
- Current
- Fixed (1, 2, or 3 years)

Features:
- Account number generation
- Initial deposit handling
- Account type selection
- Interest rate assignment

## 2. Account Information Management
```c
void updateAccountInformation(struct User u) {
    // Updates account details
    // Modifies contact information
    // Maintains account history
}
```

Updatable Fields:
- Phone number
- Country
- Account details

## 3. Account Querying
```c
void checkAllAccounts(struct User u) {
    // Lists all user accounts
    // Shows account details
    // Displays balances
}
```

```c
void checkAccountDetails(struct User u) {
    // Shows detailed account information
    // Calculates interest
    // Displays transaction history
}
```

# Part 5: Transaction Processing

## 1. Transaction Management
```c
void makeTransaction(struct User u) {
    // Handles deposits/withdrawals
    // Validates transactions
    // Updates account balances
}
```

Features:
- Transaction type validation
- Balance verification
- Account update
- Transaction history

## 2. Account Removal
```c
void removeAccount(struct User u) {
    // Deletes existing accounts
    // Updates records
    // Maintains data integrity
}
```

## 3. Ownership Transfer
```c
void transferOwnership(struct User u) {
    // Transfers account ownership
    // Updates account records
    // Maintains transaction history
}
```

# Part 6: Data Storage

## 1. Users.txt Format
```
id username password
```

Example:
```
0 Alice q1w2e3r4t5y6
1 Michel q1w2e3r4t5y6
```

## 2. Records.txt Format
```
id userId name accountNbr date country phone amount accountType
```

Example:
```
0 0 Alice 0 10/10/2012 Africa 291321234 22432.52 savings
1 1 Michel 2 2/5/2001 Portugal 123543455 10023.23 fixed01
```

# Part 7: Security Features

1. Password Protection:
   - Masked password input
   - Secure storage
   - Authentication validation

2. Account Security:
   - Ownership verification
   - Transaction validation
   - Balance protection

3. Data Integrity:
   - File locking during transactions
   - Error handling
   - Data validation

# Part 8: Interest Calculation

Different account types have different interest rates:
- Savings: 7% annual
- Fixed01 (1 year): 4% annual
- Fixed02 (2 years): 5% annual
- Fixed03 (3 years): 8% annual
- Current: No interest

# Part 9: Error Handling

The system includes comprehensive error handling for:
- File operations
- User input validation
- Transaction processing
- Account operations
- Authentication failures

# Part 10: User Interface

The system provides a clear, menu-driven interface with:
- Clear prompts
- Error messages
- Success confirmations
- Navigation options
- Help messages 

# Part 11: Detailed Function Explanations

## Authentication Functions

### 1. initMenu(struct User *u)
```c
void initMenu(struct User *u)
```
**Purpose**: Initial entry point for user interaction
**Parameters**: 
- `u`: Pointer to User structure to store user information
**Functionality**:
- Displays main menu with login/register options
- Handles user input for menu selection
- Manages authentication flow
- Calls appropriate functions based on user choice

### 2. loginMenu(char a[], char pass[])
```c
void loginMenu(char a[], char pass[])
```
**Purpose**: Handles user login process
**Parameters**:
- `a[]`: Array to store username
- `pass[]`: Array to store password
**Functionality**:
- Prompts for username and password
- Masks password input for security
- Validates credentials against users.txt
- Sets up user session if authentication successful

### 3. registerMenu(char a[], char pass[])
```c
void registerMenu(char a[], char pass[])
```
**Purpose**: Handles new user registration
**Parameters**:
- `a[]`: Array to store new username
- `pass[]`: Array to store new password
**Functionality**:
- Prompts for new username and password
- Checks username uniqueness
- Creates new user entry in users.txt
- Assigns unique user ID

## Account Management Functions

### 1. createNewAccount(struct User u)
```c
void createNewAccount(struct User u)
```
**Purpose**: Creates new bank account
**Parameters**:
- `u`: User structure containing user information
**Functionality**:
- Prompts for account type selection
- Handles initial deposit
- Generates unique account number
- Stores account information in records.txt
- Sets up interest rates based on account type

### 2. updateAccountInformation(struct User u)
```c
void updateAccountInformation(struct User u)
```
**Purpose**: Updates existing account details
**Parameters**:
- `u`: User structure containing user information
**Functionality**:
- Allows modification of contact information
- Updates phone number and country
- Maintains account history
- Updates records.txt with new information

### 3. checkAllAccounts(struct User u)
```c
void checkAllAccounts(struct User u)
```
**Purpose**: Displays all accounts owned by user
**Parameters**:
- `u`: User structure containing user information
**Functionality**:
- Retrieves all accounts from records.txt
- Displays account numbers and balances
- Shows account types and status
- Provides account overview

### 4. checkAccountDetails(struct User u)
```c
void checkAccountDetails(struct User u)
```
**Purpose**: Shows detailed account information
**Parameters**:
- `u`: User structure containing user information
**Functionality**:
- Displays detailed account information
- Calculates and shows interest rates
- Shows transaction history
- Displays account creation date

## Transaction Functions

### 1. makeTransaction(struct User u)
```c
void makeTransaction(struct User u)
```
**Purpose**: Handles deposits and withdrawals
**Parameters**:
- `u`: User structure containing user information
**Functionality**:
- Processes deposits and withdrawals
- Validates transaction amounts
- Updates account balances
- Maintains transaction history
- Applies interest calculations

### 2. removeAccount(struct User u)
```c
void removeAccount(struct User u)
```
**Purpose**: Deletes existing accounts
**Parameters**:
- `u`: User structure containing user information
**Functionality**:
- Verifies account ownership
- Removes account from records.txt
- Updates account records
- Maintains data integrity

### 3. transferOwnership(struct User u)
```c
void transferOwnership(struct User u)
```
**Purpose**: Transfers account ownership
**Parameters**:
- `u`: User structure containing user information
**Functionality**:
- Verifies current ownership
- Validates new owner existence
- Updates account records
- Maintains transaction history
- Updates ownership information

## Utility Functions

### 1. getUserId(const char *username)
```c
int getUserId(const char *username)
```
**Purpose**: Retrieves user ID from username
**Parameters**:
- `username`: String containing username
**Functionality**:
- Searches users.txt for username
- Returns corresponding user ID
- Returns -1 if user not found

### 2. doesUserHaveAccounts(struct User u)
```c
int doesUserHaveAccounts(struct User u)
```
**Purpose**: Checks if user has any accounts
**Parameters**:
- `u`: User structure containing user information
**Functionality**:
- Searches records.txt for user accounts
- Returns 1 if accounts exist
- Returns 0 if no accounts found

### 3. stayOrReturn(int notGood, void f(struct User u), struct User u)
```c
void stayOrReturn(int notGood, void f(struct User u), struct User u)
```
**Purpose**: Handles navigation after operations
**Parameters**:
- `notGood`: Error status flag
- `f`: Function pointer for retry
- `u`: User structure containing user information
**Functionality**:
- Provides options to retry operation
- Returns to main menu
- Exits program
- Handles error cases

### 4. success(struct User u)
```c
void success(struct User u)
```
**Purpose**: Handles successful operation completion
**Parameters**:
- `u`: User structure containing user information
**Functionality**:
- Displays success message
- Provides navigation options
- Returns to main menu or exits

## File Operation Functions

### 1. getAccountFromFile(FILE *ptr, char name[], struct Record *r)
```c
int getAccountFromFile(FILE *ptr, char name[], struct Record *r)
```
**Purpose**: Reads account information from file
**Parameters**:
- `ptr`: File pointer
- `name`: Array to store username
- `r`: Pointer to Record structure
**Functionality**:
- Reads account record from file
- Parses record information
- Returns success/failure status

### 2. saveAccountToFile(FILE *ptr, struct User u, struct Record r)
```c
void saveAccountToFile(FILE *ptr, struct User u, struct Record r)
```
**Purpose**: Saves account information to file
**Parameters**:
- `ptr`: File pointer
- `u`: User structure
- `r`: Record structure
**Functionality**:
- Formats account information
- Writes to records.txt
- Maintains file structure

### 3. updateUserAccountInFile(FILE *ptr, struct Record r)
```c
void updateUserAccountInFile(FILE *ptr, struct Record r)
```
**Purpose**: Updates account information in file
**Parameters**:
- `ptr`: File pointer
- `r`: Record structure
**Functionality**:
- Updates existing account record
- Maintains file integrity
- Preserves record format 

# Part 12: Detailed Function Analysis

## createNewAccount Function - Complete Breakdown

### Overview
The `createNewAccount` function is responsible for creating a new bank account for a user. Let's break it down step by step.

### Function Signature
```c
void createNewAccount(struct User u)
```
- `void`: The function doesn't return anything
- `struct User u`: Takes a User structure as parameter containing the user's information

### Step-by-Step Breakdown

#### 1. Variable Declarations
```c
struct Record r;        // Holds the new account information
FILE *pf;              // File pointer for writing to records.txt
int accountNbr;        // Stores the new account number
int recordCount = 0;   // Counts total records in the file
```
- `struct Record r`: Creates a new Record structure to store account details
- `FILE *pf`: Creates a pointer to handle file operations
- `int accountNbr`: Will store the new account number
- `int recordCount`: Keeps track of how many records exist

#### 2. Account Type Selection
```c
printf("\n\t\tEnter the account type:\n");
printf("\n\t\t[1]- Savings\n");
printf("\n\t\t[2]- Current\n");
printf("\n\t\t[3]- Fixed01 (1 year)\n");
printf("\n\t\t[4]- Fixed02 (2 years)\n");
printf("\n\t\t[5]- Fixed03 (3 years)\n");
scanf("%d", &option);
```
- Shows menu of available account types
- User selects account type by entering a number
- `option` stores the user's choice

#### 3. Account Type Assignment
```c
switch (option) {
    case 1:
        strcpy(r.accountType, "savings");
        break;
    case 2:
        strcpy(r.accountType, "current");
        break;
    case 3:
        strcpy(r.accountType, "fixed01");
        break;
    case 4:
        strcpy(r.accountType, "fixed02");
        break;
    case 5:
        strcpy(r.accountType, "fixed03");
        break;
    default:
        printf("\n\t\tInvalid option!\n");
        return;
}
```
- Uses switch statement to handle user's choice
- Copies appropriate account type string to `r.accountType`
- If invalid option selected, exits function

#### 4. Initial Deposit
```c
printf("\n\t\tEnter the initial deposit amount: $");
scanf("%lf", &r.amount);
```
- Prompts user for initial deposit amount
- Stores amount in `r.amount` (double type for decimal values)

#### 5. Account Number Generation
```c
pf = fopen(RECORDS, "r");
if (pf == NULL) {
    printf("\n\t\tError opening file!\n");
    return;
}

while (getAccountFromFile(pf, r.name, &r)) {
    recordCount++;
}
accountNbr = recordCount + 1;
```
- Opens records.txt file for reading
- Counts existing records to generate new account number
- New account number = total records + 1
- Closes file after counting

#### 6. Setting Account Details
```c
r.id = recordCount;
r.userId = u.id;
strcpy(r.name, u.name);
r.accountNbr = accountNbr;
r.phone = 0;  // Default phone number
strcpy(r.country, "N/A");  // Default country
```
- Sets unique record ID
- Links account to user ID
- Copies user's name
- Assigns generated account number
- Sets default phone and country

#### 7. Setting Date
```c
time_t t = time(NULL);
struct tm *tm = localtime(&t);
r.deposit.year = tm->tm_year + 1900;
r.deposit.month = tm->tm_mon + 1;
r.deposit.day = tm->tm_mday;
```
- Gets current system date
- Stores deposit date in the record
- Uses time.h functions for date handling

#### 8. Saving to File
```c
pf = fopen(RECORDS, "a");
if (pf == NULL) {
    printf("\n\t\tError opening file!\n");
    return;
}

saveAccountToFile(pf, u, r);
fclose(pf);
```
- Opens records.txt in append mode
- Saves new account record to file
- Closes file after saving

#### 9. Success Message
```c
printf("\n\t\t✔ Account created successfully!\n");
success(u);
```
- Displays success message
- Calls success function to handle next steps

### Important Notes for Beginners
1. File Operations:
   - Always check if file opens successfully
   - Close files after use
   - Use appropriate file modes (read "r", write "w", append "a")

2. Error Handling:
   - Function includes basic error checking
   - Exits gracefully if errors occur

3. Data Types:
   - `double` for money amounts (allows decimals)
   - `int` for whole numbers
   - `char[]` for text strings

4. Structure Usage:
   - `struct User` holds user information
   - `struct Record` holds account information

5. String Operations:
   - Use `strcpy()` to copy strings
   - String arrays need enough space for content

### Common Pitfalls to Avoid
1. Not checking file operations
2. Forgetting to close files
3. Not validating user input
4. Not handling memory properly
5. Not checking array bounds 