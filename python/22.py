def generateParenthesis(n):
    def generate(p, left, right, parens=[]):
        if left:         # Add an open parenthesis if we can
            generate(p + '(', left-1, right)
        if right > left:  # Add a close parenthesis if it balances an open parenthesis
            generate(p + ')', left, right-1)
        if not right:     # If there are no more right parentheses, it's a valid combination
            parens += [p]
        return parens

    return generate('', n, n)

n = 3
combinations = generateParenthesis(n)
for combination in combinations:
    print(combination)