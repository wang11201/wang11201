package Utils;

import java.io.*;

public class TextUtils {
    /**
     * 读取txt文件
     * 读取文件路径，将文件文本以字符串输入程序
     * @param textPath
     * @return 文件文本
     */
    public static String readText(String textPath){
        String str = "";
        String strLine;
        //按行读取文件到字符串str
        File file = new File(textPath);
        FileInputStream fileInputStream = null;
        try {
            fileInputStream = new FileInputStream(file);
            InputStreamReader inputStreamReader = new InputStreamReader(fileInputStream,"UTF-8");
            BufferedReader bufferedReader = new BufferedReader(inputStreamReader);
            while ((strLine = bufferedReader.readLine())!= null ){
                str += strLine;
            }
            inputStreamReader.close();
            bufferedReader.close();
            fileInputStream.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
        return str;
    }

    /**
     * 写入文件
     * @param textElem
     * @param textPath
     */
    public static void writeText(double textElem,String textPath){
        String str = Double.toString(textElem);
        File file = new File(textPath);
        FileWriter fileWriter = null;
        try
        {
            fileWriter = new FileWriter(file,true);
            fileWriter.write(str,0,(str.length()>3?4:str.length()));
            fileWriter.write("\r\n");
            fileWriter.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}

