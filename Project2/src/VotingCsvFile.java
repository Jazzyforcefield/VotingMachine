import java.awt.BorderLayout;
import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import javax.swing.JTextField;
import javax.swing.JButton;
import javax.swing.JFileChooser;

import java.awt.event.ActionListener;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.awt.event.ActionEvent;
import javax.swing.SwingConstants;
import java.awt.Color;
/**
 * Show the interface that users could select the CSV file from any dictionary
 * and we can run the algorithm. 
 * @author      YongFeng Ji
 * @version     2.0         
 * @since       12/08/2019
 */

public class VotingCsvFile extends JFrame {

	private JPanel contentPane;
	private JTextField path;
	private JTextField panduan;
	private JButton run;

	/**
	   * This is the main method which call the frame(Interface)
	   * @param args Unused.
	   * @return Nothing.
	   */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					VotingCsvFile frame = new VotingCsvFile();
					frame.setVisible(true);
					frame.setResizable(false);
					frame.setTitle("Interface for searching file");
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	/**
	   * This is the interface function
	   * @param none.
	   * @return Nothing.
	   */
	public VotingCsvFile() {
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 450, 300);
		contentPane = new JPanel();
		contentPane.setBackground(Color.ORANGE);
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		contentPane.setLayout(null);
		
		path = new JTextField();
		path.setBounds(79, 38, 290, 37);
		contentPane.add(path);
		path.setColumns(10);
		path.setEditable(false);
		
		
		JButton FileOpen = new JButton("SelectPath");
		FileOpen.addActionListener(new ActionListener() {
			/**
			   * This is the search file function button
			   * @param none.
			   * @return Nothing.
			   */
			public void actionPerformed(ActionEvent e) {
				// use the Filechooser in order to be able to select file
				JFileChooser chooser = new JFileChooser();
				chooser.showOpenDialog(null);
				File f = chooser.getSelectedFile();
				String filename = f.getAbsolutePath();
				// set the textfield(path) to the file's path we just chose
				path.setText(filename);
				// create location and name
				File f1 = new File("path.txt");
				// write file to the location.
				try {
					FileWriter fw = new FileWriter(f1);
					String text = path.getText();
					fw.write(text);
					fw.close();
					// make the textfield to "File Choosen"
					panduan.setText("File Choosen");
				}
				catch(IOException e2) {
					JOptionPane.showMessageDialog(null, "Boom");
				}
			}
		});
		FileOpen.setBounds(156, 112, 141, 29);
		contentPane.add(FileOpen);
		
		panduan = new JTextField();
		panduan.setHorizontalAlignment(SwingConstants.CENTER);
		panduan.setText("No File Choosen");
		panduan.setBounds(156, 165, 141, 26);
		contentPane.add(panduan);
		panduan.setColumns(10);
		
		run = new JButton("Run the System");
		run.addActionListener(new ActionListener() {
			/**
			   * This is the run function button
			   * @param none.
			   * @return Nothing.
			   */
			public void actionPerformed(ActionEvent e) {
				// This is the run button, if we click and select yes, 
				// the system is going to run the result
				int answer;
				answer = JOptionPane.showConfirmDialog
						(null,"If you click yes, you are about to close the interface");
				if(answer == JOptionPane.YES_OPTION) {
					// if yes, interface close
					System.exit(0);
				}
			}
		});
		run.setBounds(156, 221, 141, 29);
		contentPane.add(run);
	}
}
