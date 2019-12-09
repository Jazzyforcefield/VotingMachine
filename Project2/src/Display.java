import java.awt.BorderLayout;
import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.border.EmptyBorder;
import javax.swing.JTextArea;
import javax.swing.JButton;
import javax.swing.JFileChooser;

import java.awt.event.ActionListener;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.awt.event.ActionEvent;
import java.awt.Color;
import javax.swing.JTextField;

/**
 * To run the display interface in order to save 
 * the file and display the audit file.
 * 
 * @author      YongFeng Ji
 * @version     2.0         
 * @since        12/08/2019
 */

public class Display extends JFrame {

	private JPanel contentPane;

	/**
	   * This is the main method which call the frame(Interface)
	   * @param args Unused.
	   */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					Display frame = new Display();
					frame.setVisible(true);
					frame.setTitle("Display the audit file, and save it");

				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	/**
	   * This is the interface function
	   */
	public Display() {
		setBackground(Color.PINK);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 450, 300);
		contentPane = new JPanel();
		contentPane.setBackground(Color.PINK);
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		contentPane.setLayout(new BorderLayout(0, 0));
		setContentPane(contentPane);
		
		JTextArea audit = new JTextArea();
		contentPane.add(audit, BorderLayout.CENTER);
		// Make the textarea not editable.
		audit.setEditable(false);
		// Scroll bar for textarea.
		JScrollPane scroll = new JScrollPane
				(audit,JScrollPane.VERTICAL_SCROLLBAR_AS_NEEDED,JScrollPane.HORIZONTAL_SCROLLBAR_AS_NEEDED );
		contentPane.add(scroll);
		BufferedReader audittext = null;
		// read the audit file that generated from algorithm, and write to the textarea.
		try {
			audittext = new BufferedReader(new FileReader("audit.txt"));
			String line = "";
			String s = "";
			while ((line = audittext.readLine())!= null) {
				s = s+line+"\n";	
			}
			audit.setText(s);	
		}
		catch(IOException e2) {
			JOptionPane.showMessageDialog(null, "Could you just have your audit file first?");
			// if no audit file, interface shut down.
			System.exit(0);
		}
		JButton btnSaveTheFile = new JButton("Save the file");
		btnSaveTheFile.addActionListener(new ActionListener() {
			/**
			   * This is the save function button
			   * @param none.
			   * @return Nothing.
			   */
			public void actionPerformed(ActionEvent e) {
				JFileChooser saveaudit = new JFileChooser() ;
				saveaudit.showSaveDialog(null);
				File f2 = saveaudit.getSelectedFile();
				// use the filechooser to save the file to any directory.
				try {
					FileWriter fw = new FileWriter(f2);
					String text = audit.getText();
					fw.write(text);
					fw.close();
					int answer1;
					//to check if u save, exit or not
					answer1 = JOptionPane.showConfirmDialog
							(null,"Successfully save, want to exit?");
					if(answer1 == JOptionPane.YES_OPTION) {
						// if yes, interface close
						System.exit(0);
					}
				}
				catch(IOException e2) {
					JOptionPane.showMessageDialog(null, "Boom");
				}
			}
		});
		contentPane.add(btnSaveTheFile, BorderLayout.EAST);
	}

}
