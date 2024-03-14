import PySimpleGUI as sg

# Dictionary to hold user account information
user_accounts = {
    'Md.Ferdaus': {'password': 'ferdaws2021', 'balance': 5000000},
    'Ruma Akhter': {'password': 'Rumu333', 'balance': 30000000}
}

# Function to handle user login
def login_layout():
    layout = [
        [sg.Text('Username', text_color='white'), sg.InputText(key='-USERNAME-', background_color='black')],
        [sg.Text('Password', text_color='white'), sg.InputText(key='-PASSWORD-', password_char='*', background_color='black')],
        [sg.Button('Login'), sg.Button('Exit')]
    ]
    window = sg.Window('Login', layout, resizable=True)
    while True:
        event, values = window.read()
        if event == sg.WINDOW_CLOSED or event == 'Exit':
            break
        elif event == 'Login':
            user_name = values['-USERNAME-']
            password = values['-PASSWORD-']
            if user_name in user_accounts and password == user_accounts[user_name]['password']:
                window.close()
                return user_name
            else:
                sg.popup_error('Invalid username or password')
    window.close()
    return None

# Function to handle withdrawal
def withdraw_layout(user_name):
    layout = [
        [sg.Text('Amount to withdraw', text_color='white'), sg.InputText(key='-AMOUNT-', background_color='black')],
        [sg.Button('Withdraw'), sg.Button('Back')]
    ]
    window = sg.Window('Withdraw', layout, resizable=True)
    while True:
        event, values = window.read()
        if event == sg.WINDOW_CLOSED or event == 'Back':
            break
        elif event == 'Withdraw':
            amount = int(values['-AMOUNT-'])
            if 0 < amount <= user_accounts[user_name]['balance']:
                user_accounts[user_name]['balance'] -= amount
                sg.popup('Take your cash')
                sg.popup('Remaining balance: {}'.format(user_accounts[user_name]['balance']))
            else:
                sg.popup_error('Invalid amount or insufficient balance')
    window.close()

# Function to handle deposit
def deposit_layout(user_name):
    layout = [
        [sg.Text('Amount to deposit', text_color='white'), sg.InputText(key='-AMOUNT-', background_color='black')],
        [sg.Button('Deposit'), sg.Button('Back')]
    ]
    window = sg.Window('Deposit', layout, resizable=True)
    while True:
        event, values = window.read()
        if event == sg.WINDOW_CLOSED or event == 'Back':
            break
        elif event == 'Deposit':
            amount = int(values['-AMOUNT-'])
            if amount > 0:
                user_accounts[user_name]['balance'] += amount
                sg.popup('Deposit successful')
                sg.popup('Current balance: {}'.format(user_accounts[user_name]['balance']))
            else:
                sg.popup_error('Invalid amount')
    window.close()

# Function to handle complaints
def complaint_layout(user_name):
    layout = [
        [sg.Text('Issue to report', text_color='white'), sg.InputText(key='-ISSUE-', background_color='black')],
        [sg.Button('Submit'), sg.Button('Back')]
    ]
    window = sg.Window('Complaint', layout, resizable=True)
    while True:
        event, values = window.read()
        if event == sg.WINDOW_CLOSED or event == 'Back':
            break
        elif event == 'Submit':
            issue = values['-ISSUE-']
            sg.popup('Thank you for contacting us about: {}'.format(issue))
            break
    window.close()

# Main function
def main():
    sg.theme('DarkAmber')
    layout = [
        [sg.Text("Welcome to Our ATM System!", text_color='white')],
        [sg.Button('Login'), sg.Button('Exit')]
    ]
    window = sg.Window('Banking System', layout, resizable=True)
    while True:
        event, values = window.read()
        if event == sg.WINDOW_CLOSED or event == 'Exit':
            break
        elif event == 'Login':
            user_name = login_layout()
            if user_name:
                sg.popup('Welcome {}'.format(user_name))
                while True:
                    layout = [
                        [sg.Button('Withdraw'), sg.Button('Deposit'), sg.Button('Check Balance'), sg.Button('Complaint'), sg.Button('Exit')]
                    ]
                    event, values = sg.Window('Options', layout, resizable=True).read(close=True)
                    if event == sg.WINDOW_CLOSED or event == 'Exit':
                        break
                    elif event == 'Withdraw':
                        withdraw_layout(user_name)
                    elif event == 'Deposit':
                        deposit_layout(user_name)
                    elif event == 'Check Balance':
                        sg.popup('Your current balance is: {}'.format(user_accounts[user_name]['balance']))
                    elif event == 'Complaint':
                        complaint_layout(user_name)
    window.close()

if __name__ == "__main__":
    main()
