PI = 3.14

def main():
    fh = open("1_parcial/pdata3.txt")
    
    for line in fh:
        m = float(line)
        error = (PI - m) / PI
        error_percent = round(abs(error), 2)*100
        print("{0}%".format(error_percent))

main()