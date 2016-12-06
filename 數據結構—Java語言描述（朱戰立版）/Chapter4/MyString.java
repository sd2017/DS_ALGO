public class MyString
{
    private char[] value;           //私有成员变量，字符数组
    private int count;              //私有成员变量，字符个数

    private static void arrayCopy(char[] src, int srcPos,
                                  char[] dst, int dstPos, int length)         //字符数组拷贝
    {
        //src为源串的字符数组，srcPos为源串的起始下标
        //dst为目标串的字符数组，srcPos为目标串的起始下标
        //length为新串的长度
        if (src.length - srcPos < length || dst.length - dstPos < length) {
            throw new StringIndexOutOfBoundsException(length);
        }

        for (int i = 0; i < length; i++) {
            dst[dstPos++] = src[srcPos++];
        }
    }

    public MyString()                           //构造函数1
    {
        value = new char[0];
        count = 0;
    }

    public MyString(char[] value, int offset, int count) //构造函数2
    {
        //value为字符数组，offset为数组起始下标，count为个数
        //即用value数组中从offset下标始、个数为count的字符串创建对象
        if (offset < 0) {
            throw new StringIndexOutOfBoundsException(offset);
        }

        if (count < 0) {
            throw new StringIndexOutOfBoundsException(count);
        }

        if (offset > value.length - count) {
            throw new StringIndexOutOfBoundsException(offset + count);
        }

        this.value = new char[count];
        this.count = count;
        arrayCopy(value, offset, this.value, 0, count); //数组元素拷贝
    }

    public MyString(char[] value)                       //构造函数3
    {
        this.count = value.length;
        this.value = new char[count];
        arrayCopy(value, 0, this.value, 0, count);      //数组元素拷贝
    }

    public MyString(String str)                         //构造函数4
    {
        //此构造函数是为了给串初始化赋值方便，否则程序中不能使用
        //类同MyString ms4 = new MyString("zhangxuhui")的语句
        char[] chararray = str.toCharArray();
        value = chararray;
        count = chararray.length;
    }

    public char charAt(int index)                       //取字符
    {
        if ((index < 0) || (index >= count)) {
            throw new StringIndexOutOfBoundsException(index);
        }

        return value[index];
    }

    public int compareTo(MyString anotherString)        //比较串
    {
        //若当前对象的串值大于anotherString的串值函数返回一个正整数
        //若当前对象的串值等于anotherString的串值函数返回0
        //若当前对象的串值小于anotherString的串值函数返回一个负整数
        int len1 = count;
        int len2 = anotherString.count;
        int n = Math.min(len1, len2);   //n为len1和len2的较小者
        char v1[] = value;
        char v2[] = anotherString.value;
        int i = 0;
        int j = 0;

        int k = i;
        int lim = n + i;

        while (k < lim) {
            char c1 = v1[k];
            char c2 = v2[k];

            if (c1 != c2) {
                return c1 - c2;          //返回第一个不相等字符的数值差
            }

            k++;
        }

        //当前边部分字符比较全部相等时
        return len1 - len2;                 //返回两个字符串长度的数值差
    }

    public int length()                                 //取串长度
    {
        return count;
    }

    public MyString concat(MyString str)                //连接
    {
        int otherLen = str.length();
        char[] strarray = str.toArray();

        if (otherLen == 0) {
            return this;
        }

        char buf[] = new char[count + otherLen];
        arrayCopy(value, 0, buf, 0, count);                     //字符数组拷贝
        arrayCopy(strarray, 0, buf, count, otherLen);       //字符数组拷贝
        return new MyString(buf);
    }

    public MyString substring(int beginIndex, int endIndex)  //取子串
    {
        //所取子串从下标beginIndex开始至下标endIndex的前一位置
        if (beginIndex < 0) {
            throw new StringIndexOutOfBoundsException(beginIndex);
        }

        if (endIndex > count) {
            throw new StringIndexOutOfBoundsException(endIndex);
        }

        if (beginIndex > endIndex) {
            throw new StringIndexOutOfBoundsException(endIndex - beginIndex);
        }

        return ((beginIndex == 0) && (endIndex == count)) ? this :
               new MyString(value, beginIndex, endIndex - beginIndex);
    }

    public MyString substring(int beginIndex)           //取子串
    {
        //所取子串从下标beginIndex开始至串的末尾
        return substring(beginIndex, count);
    }

    public char[] toArray()                         //转换成字符数组
    {
        char[] buf = new char[count];
        arrayCopy(value, 0, buf, 0, count);
        return buf;
    }

    public MyString insert(MyString str, int pos)       //插入子串
    {
        //在当前对象字符数组的pos下标开始插入str对象的字符串
        if (pos < 0 || pos > count) {
            throw new StringIndexOutOfBoundsException(pos);
        }

        if (pos != 0) {
            MyString str1 = this.substring(0, pos); //取出主串的前一部分
            MyString str2 = this.substring(pos); //取出主串的后一部分
            MyString res1 = str1.concat(str);   //连接str1和str
            MyString res2 = res1.concat(str2);  //连接str1和str2
            return res2;                            //返回str2
        } else {
            return str.concat(this);
        }
    }

    public MyString delete(int beginIndex, int endIndex) //删除子串
    {
        //删除当前对象从下标beginIndex开始至下标endIndex的前一位置的子串
        if (beginIndex < 0) {
            throw new StringIndexOutOfBoundsException(beginIndex);
        }

        if (endIndex > count) {
            throw new StringIndexOutOfBoundsException(endIndex);
        }

        if (beginIndex > endIndex) {
            throw new StringIndexOutOfBoundsException(endIndex - beginIndex);
        }

        if ((beginIndex == 0) && (endIndex == count)) {
            return new MyString();    //返回串值为空的对象
        } else {
            MyString str1 = this.substring(0, beginIndex);
            //取出主串的前一部分
            MyString str2 = this.substring(endIndex);
            //取出主串的后一部分
            return str1.concat(str2);       //连接str1和str2并返回
        }
    }

    public void myPrint()                       //输出串值
    {
        for (int i = 0; i < count; i++) {
            System.out.print(value[i]);
        }

        System.out.println();
    }

    public int indexOf_BF(MyString subStr, int start)
    {
        //查找当前对象（即主串）中从start始的子串subStr
        //找到到则返回子串subStr在主串的开始字符下标，否则返回-1
        int i = start, j = 0, v ;

        while (i < this.length() && j < subStr.length()) {
            if (this.charAt(i) == subStr.charAt(j)) {
                i ++ ;
                j ++ ;
            } else {
                i = i - j + 1 ;
                j = 0 ;
            }
        }

        if (j == subStr.length()) {
            v = i - subStr.length() ;
        } else {
            v = -1 ;
        }

        return v;
    }

    public int indexOf_KMPA(MyString subStr, int start)
    {
        //查找当前对象（即主串）中从start始的子串subStr
        //找到到则返回子串subStr在主串的开始字符下标，否则返回-1
        int[] next = getNext(subStr);   //求子串subStr的next[j]值
        int i = start, j = 0, v;

        while (i < this.length() && j < subStr.length()) {
            if (j == -1 || this.charAt(i) == subStr.charAt(j)) {
                i ++ ;
                j ++ ;
            } else {
                j = next[j];
            }
        }

        if (j == subStr.length()) {
            v = i - subStr.length();
        } else {
            v = -1;
        }

        return v;
    }

    public int indexOf_KMPB(MyString subStr, int start)
    {
        int[] next = getNext(subStr);
        int i = start, j = 0, v;

        while (i < this.length() && j < subStr.length()) {
            if (this.charAt(i) == subStr.charAt(j)) {
                i ++ ;
                j ++ ;
            } else if (j == 0) {
                i ++ ;
            } else {
                j = next[j];
            }
        }

        if (j == subStr.length()) {
            v = i - subStr.length();
        } else {
            v = -1;
        }

        return v;
    }

    private int[] getNext(MyString str)
    {
        //求模式串str的next[j]函数值并用数组返回
        int j = 1, k = 0 ;
        int[] next = new int[str.length()];

        next[0] = -1 ;
        next[1] = 0 ;

        while (j < str.length() - 1) {
            if (str.charAt(j) == str.charAt(k)) {
                next[j + 1] = k + 1 ;
                j ++ ;
                k ++ ;
            } else if (k == 0) {
                next[j + 1] = 0 ;
                j ++ ;
            } else {
                k = next[k];
            }
        }

        return next ;
    }

    public int indexOf_BF_Count(MyString subStr, int start)
    {
        //查找当前对象（即主串）中从start始的子串subStr
        //找到到则返回子串subStr在主串的开始字符下标，否则返回-1
        int i = start, j = 0, v ;
        int count = 0;

        while (i < this.length() && j < subStr.length()) {
            if (this.charAt(i) == subStr.charAt(j)) {
                i ++ ;
                j ++ ;
            } else {
                i = i - j + 1 ;
                j = 0 ;
            }

            count++;
        }

        return count;
    }

    public int indexOf_KMPB_Count(MyString subStr, int start)
    {
        int[] next = getNext(subStr);
        int i = start, j = 0, v;
        int count = 0;

        while (i < this.length() && j < subStr.length()) {
            if (this.charAt(i) == subStr.charAt(j)) {
                i ++ ;
                j ++ ;
            } else if (j == 0) {
                i ++ ;
            } else {
                j = next[j];
            }

            count++;
        }

        return count;
    }
}
