import _grafo
while True:
    print "[1] Crar grafo vacio\n[2] Crear con cantidad de nodos a especificar\n"
    option = raw_input()
    the_grafo = ""
    if option == "1":
        the_grafo = _grafo.new_grafo()
    elif option == "2":
        n_nodes = int(raw_input("Ingrese el numero de nodos\n"))
        the_grafo = _grafo.new_grafo(n_nodes)
    else:
        print "No ingreso un valor valido\n"
        continue
    opt_add_nodes = raw_input("Desea agregar mas nodos? \n[1 SI]\n[0 NO]")
    if opt_add_nodes == "1":
        count = int(raw_input("Ingrese cuantos desea agregar\n"))
        n_nodes += count
        for i in count:
            _grafo.grafo_add_node(the_grafo)
    print "Ingrese los numeros de los nodos separados por coma y despues el peso para agregar el arco, por ejemplo 1,3,2"
    print "Ingrese -1 para terminar"
    while True:
        opt = raw_input()
        if opt == "-1":
            break
        else:
            list = opt.split(",")
            if len(list) < 3 or int(list[0]) < 0 or int(list[0]) > n_nodes - 1 or int(list[1]) < 0 or int(list[1]) > n_nodes - 1 :
                print "No ingreso un input en formato valido, intentelo denuevo"
                continue
            _grafo.grafo_add_arco(the_grafo, int(list[0]), int(list[1]), int(list[2]))
            print "Arco agregado correctamente"
    while True:
        opt = raw_input("[1] Hay Camino\n[2] Hay Arco\n[-1] Terminar\n")
        if opt == "1":
            print "Ingrese los numeros de los nodos separados por coma, por ejemplo 1,2"
            nodes = raw_input()
            nodes = nodes.split(",")
            if len(nodes) != 2:
                print "Ingreso un input invalido"
                continue
            have = _grafo.grafo_hay_camino(the_grafo, int(nodes[0]), int(nodes[1]))
            if have == True:
                print "Hay Camino!!"
            else:
                print "No hay Camino!"
        elif opt == "2":
            print "Ingrese los numeros de los nodos separados por coma, por ejemplo 1,2"
            nodes = raw_input()
            nodes = nodes.split(",")
            if len(nodes) != 2:
                print "Ingreso un input invalido"
                continue
            have = _grafo.grafo_hay_arco(the_grafo, int(nodes[0]), int(nodes[1]))
            if have == True:
                print "Hay Arco!!"
            else:
                print "No hay Arco!"
        elif opt == "-1":
            break
        else:
            print "No ingreso un input valido"