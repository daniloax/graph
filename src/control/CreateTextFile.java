package control;

import java.io.FileNotFoundException;
import java.util.Formatter;
import java.util.FormatterClosedException;
import java.util.NoSuchElementException;
import java.util.Scanner;

import model.Cell;

public class CreateTextFile
{
	private Formatter output;

	public void openFile() {

		try {
			output = new Formatter( "cells" );

		} catch ( SecurityException securityException ) {

			System.err.println("You do not have write access to this file." );
			System.exit( 1 );

		} catch ( FileNotFoundException fileNotFoundException ) {

			System.err.println( "Error opening or creating file." );
			System.exit( 1 );

		} 

	}

	public void addRecords() {

		Cell record = new Cell();

		Scanner input = new Scanner( System.in );

		System.out.printf( "%s\n%s\n%s\n%s\n\n",
				"To terminate input, type the end-of-file indicator ",
				"when you are prompted to enter input.",
				"On UNIX/Linux/Mac OS X type <ctrl> d then press Enter",
				"On Windows type <ctrl> z then press Enter" );

		System.out.printf( "%s\n%s", 
				"Enter cell number (> 0), cell name, x position and y position.",
				"? " );

		while ( input.hasNext() ) {

			try {

				record.setId( input.nextInt() );
				record.setName( input.next() );
				record.setX( input.nextFloat() );
				record.setY( input.nextFloat() );

				if ( record.getId() > 0 ) {

					output.format( "%d %s %.2f %.2f\n", record.getId(), 
							record.getName(), record.getX(),
							record.getY() );

				} else {

					System.out.println(
							"Cell number must be greater than 0." );

				}

			} catch ( FormatterClosedException formatterClosedException ) {

				System.err.println( "Error writing to file." );	
				return;
			
			} catch ( NoSuchElementException elementException ) {
				
				System.err.println( "Invalid input. Please try again." );
				input.nextLine();
			
			}

			System.out.printf( "%s %s\n%s", "Enter cell number (>0),",
					"cell name, x position and y position.", "? " );
		
		}
	
	} 

	public void closeFile() {
		
		if ( output != null )
			output.close();
	
	}

}

/*************************************************************************
 *                                                                        *
 *                                                                        *
 *                                                                        *
 *                                                                        *
 *                                                                        *
 *                                                                        *
 *                                                                        *
 *                                                                        *
 *                                                                        *
 *                                                                        *
 *                                                                        *
 *                                                                        *
 *************************************************************************/