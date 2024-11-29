def StringChallenge(str):
    """
    __define-ocg__: This function validates a password based on given constraints.
    """
    # Define the variable for filtering conditions
    varFiltersCg = [
        lambda s: any(c.isupper() for c in s),  # Must have at least one uppercase letter
        lambda s: any(c.isdigit() for c in s),  # Must have at least one number
        lambda s: any(c in "!@#$%^&*()_+-=~`<>?/.,:;" for c in s),  # Must contain a punctuation or math symbol
        lambda s: "password" not in s.lower(),  # Cannot contain the word "password"
        lambda s: 7 < len(s) < 31  # Length constraints: 8 to 30 characters
    ]
    
    # Use a variable named `varOcg` for the result of all conditions
    varOcg = all(check(str) for check in varFiltersCg)
    
    # Return the result as a string
    return "true" if varOcg else "false"

# Example usage
print(StringChallenge("apple!M7"))        # Output: "true"
print(StringChallenge("passWord123!!!!")) # Output: "false"
print(StringChallenge("turkey90AAA="))    # Output: "true"
