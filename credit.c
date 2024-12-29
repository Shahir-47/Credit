# **Credit**

**Credit** is a program written in C that validates credit card numbers using **Luhn's Algorithm**. The program determines whether a card number is valid and identifies the type of card (American Express, MasterCard, Visa, or INVALID) based on card number structure and checksum verification.

---

## 📖 Background

Credit card numbers are long decimal numbers that include a checksum to verify their validity. Each type of card has unique properties:

- **American Express (AMEX)**: 15 digits, starting with `34` or `37`.
- **MasterCard**: 16 digits, starting with `51`, `52`, `53`, `54`, or `55`.
- **Visa**: 13 or 16 digits, starting with `4`.

### **Luhn's Algorithm**
The program uses Luhn's Algorithm to validate the card number:
1. Multiply every second-to-last digit by 2.
2. Add the digits of the resulting products together.
3. Add this sum to the sum of the digits that weren’t multiplied by 2.
4. If the total modulo 10 is 0, the card number is valid.

---

## 🚀 How It Works

### **Input and Output**
1. The program prompts the user for a credit card number.
2. It validates the card using Luhn’s Algorithm.
3. If valid, it identifies the type of card:
   - `AMEX` for American Express.
   - `MASTERCARD` for MasterCard.
   - `VISA` for Visa.
4. If invalid, it outputs `INVALID`.

---

## 🛠 Installation

This program requires the **CS50 library**. Follow these instructions to install it:

### Install the CS50 Library:

#### **Ubuntu**
```bash
curl -s https://packagecloud.io/install/repositories/cs50/repo/script.deb.sh | sudo bash
sudo apt install libcs50
```

#### **Fedora**
```bash
curl -s https://packagecloud.io/install/repositories/cs50/repo/script.rpm.sh | sudo bash
sudo dnf install libcs50
```

#### **From Source (Linux and macOS)**
1. Download the latest release from [CS50 Library Releases](https://github.com/cs50/libcs50/releases).
2. Extract the downloaded file:
   ```bash
   tar -xvf libcs50-*.tar.gz
   cd libcs50-*
   sudo make install
   ```

---

## 💻 Usage

### **Compile the Program**
Use the following command to compile the program with the CS50 library:
```bash
gcc -o credit credit.c -lcs50
```

### **Run the Program**
Run the program using:
```bash
./credit
```

### **Example Input and Output**

#### **Valid Visa Card**
Input:
```bash
Number: 4003600000000014
```
Output:
```bash
VISA
```

#### **Invalid Card**
Input:
```bash
Number: 123456789012345
```
Output:
```bash
INVALID
```

---

## 🧪 Example Scenarios

### Scenario 1: Valid American Express Card
- Input: `378282246310005`
- Output: `AMEX`

### Scenario 2: Valid MasterCard
- Input: `5105105105105100`
- Output: `MASTERCARD`

### Scenario 3: Valid Visa (13 Digits)
- Input: `4111111111111`
- Output: `VISA`

### Scenario 4: Invalid Number
- Input: `6176292929`
- Output: `INVALID`

---

## 🔍 Code Overview

### Key Steps in the Code:
1. **Input Validation**:
   - Prompts the user for a numeric input using `get_long` from the CS50 library to handle large numbers.
   
2. **Checksum Calculation**:
   - Implements Luhn’s Algorithm:
     - Multiplies every second-to-last digit by 2.
     - Sums the digits of the products and the remaining digits.
     - Checks if the total modulo 10 equals 0.

3. **Card Type Identification**:
   - Identifies the card type based on the length and starting digits:
     - `AMEX` for 15 digits starting with `34` or `37`.
     - `MASTERCARD` for 16 digits starting with `51`–`55`.
     - `VISA` for 13 or 16 digits starting with `4`.

4. **Output**:
   - Prints the card type or `INVALID`.

---

## 🛡️ Edge Cases

1. **Invalid Length**:
   - Rejects card numbers with lengths other than 13, 15, or 16.

2. **Invalid Checksum**:
   - Outputs `INVALID` if the checksum fails.

3. **Unsupported Starting Digits**:
   - Outputs `INVALID` for valid-length numbers that don’t match known card types.

4. **Non-Numeric Input**:
   - The program ensures only numeric input is processed.

---

## 📜 Licensing

This project was developed as part of a CS50 assignment and adheres to its guidelines.

--- 
