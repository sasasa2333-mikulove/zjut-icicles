<%@ page language="java" contentType="text/html; charset=GB18030"
         pageEncoding="GB18030"
         import="com.opensymphony.xwork2.util.ValueStack,
                 java.util.List,
                 java.util.Iterator,
                 cn.edu.zjut.bean.Item" %>
<%@ taglib prefix="s" uri="/struts-tags" %>
<body>
<s:property value="#session.user"/>�����ã�
<center>��Ʒ�б�</center>
<table border=1>
    <tr>
        <th>���</th><th>����</th><th>˵��</th><th>����</th>
    </tr>
    <s:iterator value="items" >
        <tr>
            <td><s:property value="itemID"/></td>
            <td><s:property value="name"/></td>
            <td><s:property value="description"/></td>
            <td><s:property value="cost"/></td>
        </tr>
    </s:iterator>
    �۸���� 20 Ԫ����Ʒ�У�<br>
    <s:iterator value="items.{?#this.cost<20}" >
        <li><s:property value="title"/>��
            <s:property value="cost" />Ԫ</li>
    </s:iterator>
    <p>
        ����Ϊ��JAVAEE ����ʵ��ָ���̡̳�����Ʒ�ļ۸�Ϊ��
        <s:property value="items.{?#this.title=='JAVAEE ����ʵ��ָ���̳�'}.{cost}[0]"/>Ԫ
    <s:url value="items.{title}[0]"/><br>
    <s:url value="%{items.{title}[0]}"/>
</table>
</body>