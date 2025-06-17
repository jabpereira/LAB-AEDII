
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
        
        Pessoa p = new Pessoa(1, "Nico", 24);
        p.exibe();
        p.adota(c1);
        p.adota(c2);
        p.adota(c3);
        p.doa(1);
        p.exibe();
        
        Cachorro teste = p.getCachorro("Josi");
        System.out.println("Recuperei o(a) " + teste.getNome());
       
        
//        if(c1.getPeso() > c2.getPeso() && c1.getPeso() > c3.getPeso())
//            System.out.println("O cão mais pesado é o " + c1.getNome());
//        if(c2.getPeso() > c3.getPeso())
//            System.out.println("O cão mais pesado é o " + c2.getNome());
//        else
//            System.out.println("O cão mais pesado é o " + c3.getNome());
    }
}
