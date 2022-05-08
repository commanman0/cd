tt=[[0]*3 for i in range(20)]

re=input("Enter the regular Expression:- ")
re += " "
l=len(re)

i = 0
j = 1
while(i<l):
    if re[i] == 'a':
        try:
            if re[i+1] != '|' and re[i+1] !='*':
                tt[j][0] = j+1
                j += 1
            elif re[i+1] == '|' and re[i+2] =='b':
                tt[j][2]=((j+1)*10)+(j+3)
                j+=1
                tt[j][0]=j+1
                j+=1
                tt[j][2]=j+3
                j+=1
                tt[j][1]=j+1
                j+=1
                tt[j][2]=j+1
                j+=1
                i=i+2
            elif re[i+1]=='*':
                tt[j][2]=((j+1)*10)+(j+3)
                j+=1
                tt[j][0]=j+1
                j+=1
                tt[j][2]=((j+1)*10)+(j-1)
                j+=1
        except:
            tt[j][0] = j+1

    elif re[i] == 'b':
        try:
            if re[i+1] != '|' and re[i+1] !='*':
                tt[j][1] = j+1
                j += 1
            elif re[i+1]=='|' and re[i+2]=='a':
                tt[j][2]=((j+1)*10)+(j+3)
                j+=1
                tt[j][1]=j+1
                j+=1
                tt[j][2]=j+3
                j+=1
                tt[j][0]=j+1
                j+=1
                tt[j][2]=j+1
                j+=1
                i=i+2
            elif re[i+1]=='*':
                tt[j][2]=((j+1)*10)+(j+3)
                j+=1
                tt[j][1]=j+1
                j+=1
                tt[j][2]=((j+1)*10)+(j-1)
                j+=1
        except:
            tt[j][1] = j+1
        
    elif re[i]=='e' and re[i+1]!='|'and re[i+1]!='*':
        tt[j][2]=j+1
        j+=1

    elif re[i]==')' and re[i+1]=='*':

        tt[0][2]=((j+1)*10)+1
        tt[j][2]=((j+1)*10)+1
        j+=1

    i +=1

print ("Transition function is:-")
for i in range(j):
    if(tt[i][0]!=0):
        print("q[{0},a]-->{1}".format(i,tt[i][0]))
    if(tt[i][1]!=0):
        print("q[{0},b]-->{1}".format(i,tt[i][1]))
    if(tt[i][2]!=0):
        if(tt[i][2]<10):
            print("q[{0},e]-->{1}".format(i,tt[i][2]))
        else:
            print("q[{0},e]-->{1} & {2}".format(i,int(tt[i][2]/10),tt[i][2]%10))