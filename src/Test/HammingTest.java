package Test;
import Utils.SimHashUtils;
import Utils.TextUtils;
import Utils.HammingUtils;

public class HammingTest {

    public void getHammingDistanceTest() {
        String str0 = TextUtils.readText("C:/Users/wqp/IdeaProjects/untitled7/orig.txt");
        String str1 = TextUtils.readText("C:/Users/wqp/IdeaProjects/untitled7/orig_0.8_add.txt");
        int distance = HammingUtils.getHammingDistance(SimHashUtils.getSimHash(str0), SimHashUtils.getSimHash(str1));
        System.out.println("海明距离：" + distance);
        System.out.println("相似度: " + (100 - distance * 100 / 128) + "%");
    }


    public void getHammingDistanceFailTest() {
        // 测试str0.length()!=str1.length()的情况
        String str0 = "10101010";
        String str1 = "1010101";
        System.out.println(HammingUtils.getHammingDistance(str0, str1));
    }


    public void getSimilarityTest() {
        String str0 = TextUtils.readText("C:/Users/wqp/IdeaProjects/untitled7/orig.txt");
        String str1 = TextUtils.readText("C:/Users/wqp/IdeaProjects/untitled7/orig_0.8_add.txt");
        int distance = HammingUtils.getHammingDistance(SimHashUtils.getSimHash(str0), SimHashUtils.getSimHash(str1));
        double similarity = HammingUtils.getSimilarity(SimHashUtils.getSimHash(str0), SimHashUtils.getSimHash(str1));
        System.out.println("str0和str1的汉明距离: " + distance);
        System.out.println("str0和str1的相似度:" + similarity);
    }



}

