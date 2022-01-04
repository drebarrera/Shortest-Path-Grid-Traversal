fi = open("testout2","r")
f = fi.read().split('\n')
fi.close()

fo = open("info.csv", "w")
fo.write("size,nodes,iter9,visits9,runtime9,process9,iter999,visits999,runtime999,process999,iterMAX,visitsMAX,runtimeMAX,processMAX\n")
for line in f:    
    if line == "":
        continue
    if line == "-----------------------------":
        ind = 0
    else:
        ind += 1
    if ind == 1:
        r = line.split(',')[1]
    if ind == 2:
        itr = int(line.split(',')[0].replace('iter: ',''))
        visit = int(line.split(',')[1].replace(' visits: ',''))
        nodes = int(line.split(',')[2].replace(' nodes: ',''))
    if ind == 3:
        run = float(line.split(',')[0].replace('RUNTIME: ',''))
        pro = float(line.split(',')[1].replace(' PROCESS: ',''))
    if ind == 5:
        m = int(line.split(' ')[0])
        if r == '9':
            fo.write(','.join([str(m),str(nodes),str(itr),str(visit),str(run),str(pro)]))
        elif r == '999' or r == 'SHRT_MAX':
            fo.write(','+','.join([str(itr),str(visit),str(run),str(pro)]))
        if r == 'SHRT_MAX':
            fo.write('\n')

fo.close()

