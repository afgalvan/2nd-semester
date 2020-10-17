def get_data():
    acum = 0
    file_handler = open("1_parcial/pdata.txt")
    
    for line in file_handler:
        value = line.split()
        for n in value:
            acum += float(n)

    print()
    print(round(acum/len(value), 2))

get_data()
