package example.crypto;

// provides helper methods to print byte[]
import static javax.xml.bind.DatatypeConverter.printHexBinary;

import java.security.Key;

import javax.crypto.Cipher;
import javax.crypto.KeyGenerator;
import javax.crypto.spec.IvParameterSpec;

/**
 * 	 Secret key cryptography using the aes algorithm.
 */
public class SymCrypto {

    public static void main (String[] args) throws Exception {

        // check args and get plaintext
        if (args.length != 1) {
            System.err.println("args: (text)");
            return;
        }
        final String plainText = args[0];
        final byte[] plainBytes = plainText.getBytes();

        System.out.println("Text:");
        System.out.println(plainText);
        System.out.println("Bytes:");
        System.out.println(printHexBinary(plainBytes));
        

        // get a DES private key
        System.out.println("Generating AES key ...");
        KeyGenerator keyGen = KeyGenerator.getInstance("AES");
        keyGen.init(128);
        Key key = keyGen.generateKey();
        System.out.println("Key:");
        System.out.println(printHexBinary(key.getEncoded()));

        // get a DES cipher object and print the provider
        Cipher cipher = Cipher.getInstance("AES/CBC/PKCS5Padding");
        System.out.println(cipher.getProvider().getInfo());

        // encrypt using the key and the plaintext
        System.out.println("Text:");
        System.out.println(plainText);
        System.out.println("Bytes:");
        System.out.println(printHexBinary(plainBytes));

        System.out.println("Ciphering ...");
        //sample AES initialization vector
        byte[] iv ={0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
IvParameterSpec ips = new IvParameterSpec(iv);
        cipher.init(Cipher.ENCRYPT_MODE, key, ips);
        byte[] cipherBytes = cipher.doFinal(plainBytes);
        System.out.println("Result:");
        System.out.println(printHexBinary(cipherBytes));

        // decrypt the ciphertext using the same key
        System.out.println("Deciphering..." );
        cipher.init(Cipher.DECRYPT_MODE, key, ips);
        byte[] newPlainBytes = cipher.doFinal(cipherBytes);
        System.out.println("Result:");
        System.out.println(printHexBinary(newPlainBytes));

        System.out.println("Text:");
        String newPlainText = new String(newPlainBytes); 
        System.out.println(newPlainText);

    }

}
