import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.EventQueue;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

import javax.swing.JButton;
import javax.swing.JFileChooser;
import javax.swing.JFrame;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;
import javax.swing.border.EmptyBorder;

/**
 * To run the display result file interface in order to save 
 * the file and display the result file.
 * 
 * @author      YongFeng Ji
 * @version     2.0         
 * @since        12/08/2019
 */

public class Result extends JFrame {

	private JPanel contentPane;

	/**
	   * This is the main method which call the result frame(Interface)
	   * @param args Unused.
	   */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					Result frame = new Result();
					frame.setVisible(true);
					frame.setTitle("Display the Result file, and save it");

				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	/**
	   * This is the result interface function
	   */
	public Result() {
		setBackground(Color.PINK);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 450, 300);
		contentPane = new JPanel();
		contentPane.setBackground(Color.PINK);
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		contentPane.setLayout(new BorderLayout(0, 0));
		setContentPane(contentPane);
		
		JTextArea result = new JTextArea();
		contentPane.add(result, BorderLayout.CENTER);
		// Make the textarea not editable.
		result.setEditable(false);
		// Scroll bar for textarea.
		JScrollPane scroll = new JScrollPane
				(result,JScrollPane.VERTICAL_SCROLLBAR_AS_NEEDED,JScrollPane.HORIZONTAL_SCROLLBAR_AS_NEEDED );
		contentPane.add(scroll);
		BufferedReader resulttext = null;
		// read the result file that generated from algorithm, and write to the textarea.
		try {
			resulttext = new BufferedReader(new FileReader("result.txt"));
			String line = "";
			String s = "";
			while ((line = resulttext.readLine())!= null) {
				s = s+line+"\n";	
			}
			result.setText(s);	
		}
		catch(IOException e2) {
			JOptionPane.showMessageDialog(null, "Could you just have your result file first?");
			// if no result file, interface shut down. and return main interface
			Display gb1 = new Display();
			gb1.setVisible(true);
		}
		JButton btnSaveTheFile = new JButton("Save the file");
		btnSaveTheFile.addActionListener(new ActionListener() {
			/**
			   * This is the save function button
			   * @param none.
			   * @return Nothing.
			   */
			public void actionPerformed(ActionEvent e) {
				// save the result file to any directory.
				JFileChooser saveaudit = new JFileChooser() ;
				saveaudit.showSaveDialog(null);
				File f3 = saveaudit.getSelectedFile();
				// use the filechooser to save the file to any directory.
				try {
					FileWriter fw = new FileWriter(f3);
					String text = result.getText();
					fw.write(text);
					fw.close();
					int answer1;
					//to check if u save, exit or not
					answer1 = JOptionPane.showConfirmDialog
							(null,"Successfully save, want to exit?");
					if(answer1 == JOptionPane.YES_OPTION) {
						// if yes, interface close. Main interface show up
						Display gb4 = new Display();
						dispose();
						gb4.setVisible(true);
						dispose();
					}
				}
				catch(IOException e2) {
					JOptionPane.showMessageDialog(null, "Boom");
				}
			}
		});
		contentPane.add(btnSaveTheFile, BorderLayout.EAST);
		
		JButton gpback = new JButton("Go Back To Main Interface");
		gpback.addActionListener(new ActionListener() {
			/**
			   * This is the go-back function button
			   * @param none.
			   * @return main interface.
			   */
			public void actionPerformed(ActionEvent e) {
				// go back to main page 
				Display gb = new Display();
				dispose();
				gb.setVisible(true);
			}
		});
		contentPane.add(gpback, BorderLayout.SOUTH);
	}

}
