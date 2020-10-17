def main():
    pi = 0
    f_hand = open("1_parcial/pdata2.txt")
    
    for line in f_hand:
        n_list = line.split()
        n_list = [v.replace(",", ".") for v in n_list]
        n_list  = [float(n) for n in n_list]

        i = 0
        while i < len(n_list):
            pi = n_list[i+4] / n_list[i]
            print("\n{} / {}".format(n_list[i+4],n_list[i]))
            print(round(pi, 2))
            i += 1   
            if i % 4 == 0:
                i += 4

main()