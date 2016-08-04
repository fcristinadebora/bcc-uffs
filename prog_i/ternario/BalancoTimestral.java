class BalancoTrimestral{
	public static void main(String[] args){

		int gastosJaneiro = 15000;
		int gastosFevereiro = 23000;
		int gastosMarco = 17000;

		int gastosTrimestre = gastosJaneiro + gastosFevereiro + gastosMarco;
		float mediaMensal = gastosTrimestre/3;
		boolean gastoControlado = mediaMensal < 30000;

		System.out.println("Gastos trimestrais: " + gastosTrimestre + "\nGastos mensais medios: " + mediaMensal);
		System.out.println("Gastos controlados? " + (gastoControlado ? "Sim" : "Nao"));		
	}
}
