# ATM System Comparison - Procedural vs Object-Oriented Approaches

This repository contains two implementations of an ATM system, each showcasing a different programming approach. The purpose of this repository is to demonstrate the differences between **procedural programming** and **object-oriented programming (OOP)** through a simple ATM system that manages account-related operations.

## Table of Contents

1. [Overview](#overview)
2. [Procedural Implementation](#procedural-implementation)
3. [Object-Oriented Implementation](#object-oriented-implementation)
4. [How to Run](#how-to-run)
5. [Key Differences](#key-differences)
6. [Contributing](#contributing)
7. [License](#license)

---

## Overview

This repository contains two directories:

- `atm_procedural/`: A basic ATM system implemented using a **procedural approach**.
- `atm_oop/`: A more advanced ATM system implemented using **object-oriented programming (OOP)** concepts.

Both implementations allow users to perform typical ATM operations like checking balance, depositing money, and withdrawing money, but the OOP version introduces additional features and better scalability.

---

## Procedural Implementation

**Directory**: `atm_procedural/`

This version of the ATM system is written in a procedural style, using basic variables and control structures. It supports the following operations for a single account:

- Checking balance
- Depositing money
- Withdrawing money

While it is easy to understand and sufficient for basic tasks, it lacks flexibility, particularly when managing multiple accounts or adding more features.

---

## Object-Oriented Implementation

**Directory**: `atm_oop/`

This version uses **Object-Oriented Programming (OOP)** principles, making the system more modular and scalable. It includes the following features:

- Creation of multiple accounts
- Checking balance for each account
- Depositing and withdrawing money
- Transferring money between accounts

The OOP version uses classes like `Account` to encapsulate account-related data and methods, and an `ATM` class to manage multiple accounts. This structure allows for better organization and potential for future expansion of the system.

---

## How to Run

To run either version of the ATM system, follow these steps:

1. Clone this repository:
   ```bash
   git clone https://github.com/your-username/atm-system-comparison.git

2. Navigate to the desired directory (either atm_procedural/ or atm_oop/):
    cd atm_procedural   # For the procedural version
# OR
cd atm_oop          # For the OOP version

3. Compile and run the code
    g++ main.cpp -o atm
  ./atm

## Key Differences

| Feature                      | Procedural Approach                | Object-Oriented Approach          |
|------------------------------|------------------------------------|-----------------------------------|
| **Account Management**       | Single account                     | Multiple accounts                 |
| **Code Structure**           | Procedural (sequential)            | Object-Oriented (classes)         |
| **Operations Supported**     | Basic (balance, deposit, withdraw) | Advanced (add accounts, transfer) |
| **Flexibility**              | Limited                            | Highly scalable                   |
| **Data Storage**             | Simple variables                   | Encapsulated in objects           |
| **Ease of Extension**        | Difficult                          | Easy to extend and modify         |

The OOP version is designed for future extensibility, such as adding new features like account history, interest calculation, etc.

---

## Contributing

Contributions are welcome! If you have any suggestions for improvements or additional features, feel free to submit a pull request or open an issue.

---

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
