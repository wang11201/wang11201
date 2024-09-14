package Test;

import Utils.HammingUtils;
import Utils.SimHashUtils;
import Utils.TextUtils;

public class TextUtilsTest {

    public void readTxtTest() {
        // 路径存在，正常读取
        String str = TextUtils.readText("C:/Users/wqp/IdeaProjects/untitled7/orig.txt");
        String[] strings = str.split(" ");
        for (String string : strings) {
            System.out.println(string);
        }
    }


    public void writeTxtTest() {
        // 路径存在，正常写入
        double[] elem = {0.11, 0.22, 0.33, 0.44, 0.55};
        for (int i = 0; i < elem.length; i++) {
            TextUtils.writeText(elem[i], "C:/Users/wqp/IdeaProjects/untitled7/ans.txt");
        }
    }


    public void readTxtFailTest() {
        // 路径不存在，读取失败
        String str = TextUtils.readText("C:/Users/wqp/IdeaProjects/untitled7/none.txt");
    }


    public void writeTxtFailTest() {
        // 路径错误，写入失败
        double[] elem = {0.11, 0.22, 0.33, 0.44, 0.55};
        for (int i = 0; i < elem.length; i++) {
            TextUtils.writeText(elem[i], "C:/Users/wqp/IdeaProjects/untitled7/ans.txt");
        }
    }
}

