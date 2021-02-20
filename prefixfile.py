import os

option = input("Choose command:\t")
prefix = input("Enter prefix:\t")

if option == "add":
    dir = os.getcwd()
    for f in os.listdir():
        os.rename(r""+f, r""+prefix + f)
    print("Adding prefix " + prefix)

elif option == "del":
    dir = os.getcwd()
    for f in os.listdir():
        if prefix == f[:len(prefix)]:
            os.rename(r""+f, r""+f[len(prefix):])
    print("Deleting prefix " + prefix)

else :
    print("Valid commands are 'add' and 'del'")