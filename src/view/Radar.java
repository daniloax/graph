package view;

import control.CreateTextFile;

public class Radar {

	public static void main(String[] args) {
		
		CreateTextFile application = new CreateTextFile();
		application.openFile();
		application.addRecords();
		application.closeFile();

	}

}
