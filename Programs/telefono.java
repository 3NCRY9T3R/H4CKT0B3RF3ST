package telefonollamada_56;
import java.util.Scanner;
public class telefono {
	private Scanner sc;
	private int clave;
	private double costo,min;
	public void inicio() {
		sc= new Scanner(System.in);
		System.out.println("Ingrsa la clave");
		clave=sc.nextInt();
		System.out.println("Ingresa la cantidad de minutos");
		min=sc.nextDouble();
		if(clave==12) {
			costo=min*2;}
		else if(clave==15) {
			costo=min*2.2;}
		else if(clave==18) {
			costo=min*4.5;}
		else if(clave==19) {
			costo= min*3.5;}
		else if(clave==23||clave==25) {
			costo=min*6;}
		else if(clave==29) {
			costo=min*5;}
		System.out.println("EL costo de la llamada es de" +costo );}
	public static void main(String[] args) {
		// Martinez Dimas Mahonri 1796763
		telefono tl= new telefono();
		tl.inicio();
	}
}
