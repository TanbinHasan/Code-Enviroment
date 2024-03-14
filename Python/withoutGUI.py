from datetime import datetime

# Dictionary to hold user account information
user_accounts = {
    'Md.Ferdaus': {'password': 'ferdaws2021', 'balance': 5000},
    'Ruma Akhter': {'password': 'Rumu333', 'balance': 3000}
}

# Function to handle user login
def login():
    user_name = input('Enter your username: ')
    if user_name in user_accounts:
        password = input('Enter your password: ')
        if password == user_accounts[user_name]['password']:
            return user_name
        else:
            print('Incorrect password')
            return None
    else:
        print('User not found')
        return None

# Function to handle withdrawal
def withdraw(user_name):
    amount = int(input('Enter amount to withdraw: '))
    if amount > 0 and amount <= user_accounts[user_name]['balance']:
        user_accounts[user_name]['balance'] -= amount
        print('Take your cash')
        print('Remaining balance:', user_accounts[user_name]['balance'])
    else:
        print('Invalid amount or insufficient balance')

# Function to handle deposit
def deposit(user_name):
    amount = int(input('Enter amount to deposit: '))
    if amount > 0:
        user_accounts[user_name]['balance'] += amount
        print('Deposit successful')
        print('Current balance:', user_accounts[user_name]['balance'])
    else:
        print('Invalid amount')

# Function to handle complaints
def complaint(user_name):
    issue = input('What issue would you like to report? ')
    print('Thank you for contacting us about:', issue)

# Main function
def main():
    print("Welcome to Our ATM system!")
    user_name = login()
    if user_name:
        current_date = datetime.now()
        print('Successful login on', current_date.strftime("%A, %d %B, %Y %I:%M%p"))
        print('Welcome', user_name)
        while True:
            print("\nThese are the available options:")
            print('1. Withdrawal')
            print('2. Cash Deposit')
            print('3. Check Balance')
            print('4. Complaint')
            print('5. Exit')

            selected_option = input('Please select an option: ')
            if selected_option == '1':
                withdraw(user_name)
            elif selected_option == '2':
                deposit(user_name)
            elif selected_option == '3':
                print('Your current balance is:', user_accounts[user_name]['balance'])
            elif selected_option == '4':
                complaint(user_name)
            elif selected_option == '5':
                print("Thank you for banking with us. Goodbye!")
                break
            else:
                print('Invalid option. Please try again.')

if __name__ == "__main__":
    main()