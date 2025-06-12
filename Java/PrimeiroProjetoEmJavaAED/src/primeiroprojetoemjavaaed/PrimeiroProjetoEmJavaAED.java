
package primeiroprojetoemjavaaed;

//import java.util.Scanner;

public class PrimeiroProjetoEmJavaAED {

    public static void main(String[] args) {
//        Scanner sc = new Scanner(System.in);
//        int n1, n2;
//
//        System.out.println("Digite um número:");
//        n1 = sc.nextInt();
//        System.out.println("Digite outro número:");
//        n2 = sc.nextInt();
//        
//        if(n1 > n2)
//            System.out.println("O número "+ n1 +" é o maior");
//        else
//             System.out.println("O número "+ n2 +" é o maior");
//        sc.close();    
        Cachorro c1 = new Cachorro("Josi", "Pastor Alemão", 1, 15.4, 'G');
        Cachorro c2 = new Cachorro("Ellen", "Rotweiller", 3, 30.2, 'G');
        Cachorro c3 = new Cachorro("João", "Bulldog", 8, 14.4, 'P');
        
        System.out.println("Exibindo cão C1: ");
        c1.exibe();
        c1.late(5);
        
        System.out.println("\nExibindo cao C2:");
        c2.exibe();
        c2.late(2);
        
        System.out.println("\nExibindo cao C3:");
        c3.exibe();
        c3.late(7);
        
        c1.setIdade(6);
        
        if(c1.getPeso() > c2.getPeso() && c1.getPeso() > c3.getPeso())
            System.out.println("O cão mais pesado é o " + c1.getNome());
        if(c2.getPeso() > c3.getPeso())
            System.out.println("O cão mais pesado é o " + c2.getNome());
        else
            System.out.println("O cão mais pesado é o " + c3.getNome());
    }
}
