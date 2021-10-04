# Solución
# Calculo del area de un Trapecio
#  $t4=($t1 + $t2)/$t5    temp=(Base menor + base mayor)/2
#  $t5=$t4*$t1            area=temp*altura

 .data                                   #Aqui van los datos
    msg1:.asciiz "\n Dame la altura: \n"
    msg2:.asciiz "\n Dame la base menor: \n"
    msg3:.asciiz "\n Dame la base mayor: \n"
    msg4:.asciiz "\n Area: \n"
    
 .text                                  #encabezados necesarios
 .globl main


 main:                        #main es la funcion principal en MIPS32

    li $t5,2                # $t5=2 
    
                              # LEER LA ALTURA en $t1
    li $v0,4         # $v0=4 llamada al sistema para imprimir una cadena
    la $a0, msg1     # $a0= msg1, equivalente a printf("%s",msg1);
    syscall          # se ejecuta la acción "\n Dame la altura: \n"


    li $v0,5        # $v0=5 llamada al sistema para leer un valor entero
    syscall          # syscall ejecuta la acción equivalente a scanf("%d",&v0). 
                     # Después de syscall el valor leído se guarda en $v0.
    move $t1,$v0     # Copia el contenido de v0 en $t1, en este caso la Altura.

                     #LEER BASE MENOR en $t2
    li $v0,4         # $v0=4 llamada al sistema para imprimir una cadena
    la $a0, msg2     # $a0=msg2, equivalente a printf("%s",msg2);
    syscall          # se ejecuta la acción "\n Dame la base menor: \n"

    li $v0,5         # $v0=5 llamada al sistema para leer un valor entero
    syscall          # syscall ejecuta la acción equivalente a scanf("%d",&v0).
 
    move $t2,$v0     # $t2=v0 en este caso la Base menor.
                     
                #LEER BASE MAYOR en $t3
    li $v0,4         # $v0=4 llamada al sistema para imprimir una cadena
    la $a0, msg3     # $a0=msg3, equivalente a printf("%s",msg3);
    syscall          # se ejecuta la acción "\n Dame la base mayor: \n"

    li $v0,5         # $v0=5 llamada al sistema para leer un valor entero
    syscall          # syscall ejecuta la acción equivalente a scanf("%d",&v0).
    move $t3,$v0     # $t3=$v0, en este caso la Base mayor.

    jal areatrapecio    # invoca a la funcion areatrapecio
                        # En $ra se guarda la dirección y aquí es donde se regresa
                        #   de la funcion areatrapecio:         
    li $v0,4         # $v0=4 llamada al sistema para imprimir una cadena
    la $a0, msg4     # $a0=msg4, equivalente a printf("%s",msg4);
    syscall          # se ejecuta la acción "\n Area: \n"

    li $v0,1         # $v0=1 llamada al sistema para imprimir un entero
    move $a0, $t5    # Ese valor entero a imprimir debe de estar en $a0, 
                        # así que $a0=$t5
    syscall          # Imprime el resultado
    
    li $v0,10        #$v0=10 llamada al sistema para imprimir una Salir 
       syscall          # exit(1);
    

areatrapecio:         # Funcion area de un trapecio
    add $t4,$t2,$t3      # $t4= base menor + base mayor
    div $t4,$t5          # Se divide $t4 entre 2 ($t5)
    mflo $t5             # En la parte baja de $t5 se guarda el resultado
    mult $t5,$t1         # $t5 lo multiplica por la Altura
    mflo $t5             # En la parte baja de $t5 se guarda el Área 
    jr $ra               # Regresa a la siguiente dirección se dónde se 
                            # invocó la función 