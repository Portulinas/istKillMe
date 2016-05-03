package example.crypto;


// provides helper methods to print byte[]
import static javax.xml.bind.DatatypeConverter.printHexBinary;
import java.security.MessageDigest;
import javax.crypto.Cipher;
import javax.crypto.KeyGenerator;
import javax.crypto.SecretKey;
import javax.crypto.spec.IvParameterSpec;


/**
 * 	Generate a Message Authentication Code
 */
public class MessageAuthenticationCode {

    public static void main(String[] args) throws Exception {

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

        
        // generate DES secret key
        SecretKey key = generate();

        // make MAC
        System.out.println("Signing ...");
        byte[] cipherDigest = makeMAC(plainBytes, key);
        System.out.println("CipherDigest:");
        System.out.println(printHexBinary(cipherDigest));

        // verify the MAC
        System.out.println("Verifying ...");
        boolean result = verifyMAC(cipherDigest, plainBytes, key);
        System.out.println("MAC is " + (result ? "right" : "wrong"));

        // data modification ...
		    plainBytes[3] = 12;
        System.out.println("Tampered bytes:");
        System.out.println(printHexBinary(plainBytes));

        // verify the MAC
        System.out.println("Verifying again ...");
        result = verifyMAC(cipherDigest, plainBytes, key);
        System.out.println("MAC is " + (result ? "right" : "wrong"));

    }


    /** auxiliary method to generate SecretKey */
    public static SecretKey generate() throws Exception {
        // generate a DES secret key
        KeyGenerator keyGen = KeyGenerator.getInstance("AES");
        keyGen.init(128);
        SecretKey key = keyGen.generateKey();

        return key;
    }


    /** auxiliary method to calculate digest from text and cipher it */
    public static byte[] makeMAC(byte[] bytes, SecretKey key) throws Exception {

        // get a message digest object using the MD5 algorithm
        MessageDigest messageDigest = MessageDigest.getInstance("SHA-1");

        // calculate the digest and print it out
        messageDigest.update(bytes);
        byte[] digest = messageDigest.digest();
        System.out.println("Digest:");
        System.out.println(printHexBinary(digest));

        // get a DES cipher object
        Cipher cipher = Cipher.getInstance("AES/CBC/PKCS5Padding");

        //sample AES initialization vector
        byte[] iv =
         {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
        IvParameterSpec ips = new IvParameterSpec(iv);
        // encrypt the plaintext using the key
        cipher.init(Cipher.ENCRYPT_MODE, key, ips);
        byte[] cipherDigest = cipher.doFinal(digest);

        return cipherDigest;
    }


    /** auxiliary method to calculate new digest from text and compare it to the
         to deciphered digest */
    public static boolean verifyMAC(byte[] cipherDigest,
    								byte[] bytes, SecretKey key) throws Exception {

        // get a message digest object using the MD5 algorithm
        MessageDigest messageDigest = MessageDigest.getInstance("SHA-1");

        // calculate the digest and print it out
        messageDigest.update(bytes);
        byte[] digest = messageDigest.digest();
        System.out.println("New digest:");
        System.out.println(printHexBinary(digest));;

        // get a DES cipher object
        Cipher cipher = Cipher.getInstance("AES/CBC/PKCS5Padding");

        //sample AES initialization vector
        byte[] iv =
          {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
        IvParameterSpec ips = new IvParameterSpec(iv);
        // decrypt the ciphered digest using the public key
        cipher.init(Cipher.DECRYPT_MODE, key, ips);
        byte[] decipheredDigest = cipher.doFinal(cipherDigest);
        System.out.println("Deciphered Digest:");
        System.out.println(printHexBinary(decipheredDigest));

        // compare digests
        if (digest.length != decipheredDigest.length)
            return false;

        for (int i=0; i < digest.length; i++)
            if (digest[i] != decipheredDigest[i])
                return false;
        return true;
    }
}
