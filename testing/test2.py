fi = open("testout3","r")
f = fi.read().split('\n')
fi.close()

fo = open("info20.csv", "w")
fo.write("size,nodes,iter,visits,runtime,process\n")
for line in f:    
    if line == "":
        continue
    if line == "-----------------------------":
        ind = 0
    else:
        ind += 1
    if ind == 1:
        size = int(line.split('_')[0])
    if ind == 2:
        itr = int(line.split(',')[0].replace('iter: ',''))
        visit = int(line.split(',')[1].replace(' visits: ',''))
        nodes = int(line.split(',')[2].replace(' nodes: ',''))
    if ind == 3:
        run = float(line.split(',')[0].replace('RUNTIME: ',''))
        pro = float(line.split(',')[1].replace(' PROCESS: ',''))
        fo.write(','.join([str(size),str(nodes),str(itr),str(visit),str(run),str(pro)]))
        fo.write('\n')

fo.close()
