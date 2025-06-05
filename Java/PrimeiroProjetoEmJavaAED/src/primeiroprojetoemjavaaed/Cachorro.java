package primeiroprojetoemjavaaed;

public class Cachorro {
    String nome, raca;
    int idade;
    double peso;
    char porte;
    
    public Cachorro(String nome, String raca, int idade, double peso, char porte){
        this.nome = nome;
        this.raca = raca;
        this.idade = idade;
        this.peso = peso;
        this.porte = porte;
    }
    
    public void exibe(){
        System.out.println("Nome: " + nome);
        System.out.println("Raça: " + raca);
        System.out.println("Idade: " + idade);
        System.out.println("Peso: " + peso);
        System.out.println("Porte: " + porte);
    }
    public void late(int quantidade){
        for(int i = 0; i < quantidade; i++){
            if(porte == 'P')
                System.out.println("au!");
            if(porte == 'M')
                System.out.println("Au!");
            if(porte == 'G')
                System.out.println("AU!");
        }
    }
}
