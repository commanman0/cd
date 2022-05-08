keywords=["auto","break","case","char","const","continue","default","do","double",
            "else","float","for","goto","if","int","long","main","return","short",
            "signed","sizeof","static","stuct","switch","typedef","union","unsigned","void","while"]


operators=["+","-","*","/","%","++","--","==","!=",">",">=","<","<=","&&","||","!","&"
            ,"|","^","~","<<",">>","=","+=","-=","*=","/=","%="]

punctuations=[";", "(", ")", "{", "}", "[", "]"]

numbers=["0","1","2","3","4","5","6","7","8","9"]

txt_file=open("sum_c.txt", 'r')
text=txt_file.readlines()


def is_number(n):
    try:
        int(n)
        return True
    except:
        return False

for line in text:
    for i in line.strip().split(" "):

        if i in keywords:
            print(i," belongs to keyword.")
        
        elif i in operators:
            print(i," belongs to an operator.")

        elif i in punctuations:
            print(i," belongs to punctuations.")
        
        elif is_number(i):
            print(i," belomgs to number.")

        else:
            print(i," is an identifier.")
