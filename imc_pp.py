OPERATORS=set(['+', '-', '*', '/', '(', ')'])
PRICEDENCE={'+': 1, '-': 1, '*': 2, '/': 2}



def infix_to_postfix(e):
    St=[] 

    output=''

    for c in e:
        if c not in OPERATORS:
            output += c

        elif c=='(':
            St.append('(')

        elif c==')':
            while St and St[-1]!='(':
                output += St.pop()
            St.pop()

        else:
            while St and St[-1]!='(' and PRICEDENCE[c] <= PRICEDENCE[St[-1]]:
                output += St.pop()
            St.append(c)


    while St:
        output += St.pop()
    print(f'POSTFIX:- {output}')
    return output



def infix_to_prefix(e):
    ost=[]
    exp_stack=[]

    for c in e:

        if not c in OPERATORS:
            exp_stack.append(c)

        elif c=='(':
            ost.append(c)

        elif c==')':
            while ost[-1]!='(':
                op=ost.pop()
                a=exp_stack.pop()
                b=exp_stack.pop()
                exp_stack.append(op+b+a)
            ost.pop() 

        else:

            while ost and ost[-1]!='(' and PRICEDENCE[c] <= PRICEDENCE[ost[-1]]:
                op=ost.pop()
                a=exp_stack.pop()
                b=exp_stack.pop()
                exp_stack.append(op+b+a)
            ost.append(c)



    while ost:
        op=ost.pop()
        a=exp_stack.pop()
        b=exp_stack.pop()
        exp_stack.append(op+b+a)
    print(f'PREFIX:- {exp_stack[-1]}')
    return exp_stack[-1]

exp=input("Enter the expression:-")
print("INFIX:-",exp)
pre=infix_to_prefix(exp)
pos=infix_to_postfix(exp)