<%@ page language="java" contentType="text/html; charset=GBK" pageEncoding="GBK"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
  <meta http-equiv="Content-Type" content="text/html; charset=GBK">
  <title>�û���¼ҳ��</title>
  <script>
    function validateForm() {
      var username = document.getElementById("username").value;
      var password = document.getElementById("password").value;

      if (username === "" || username.length > 6) {
        alert("�û�������Ϊ���Ҳ��ܳ��� 6 λ");
        return false;
      }

      if (password === "" || password.length > 6) {
        alert("���벻��Ϊ���Ҳ��ܳ��� 6 λ");
        return false;
      }

      return true;
    }
  </script>
</head>
<body>
<form action="login" method="post" onsubmit="return validateForm()">
  <table>
    <tr>
      <td>�������û�����</td>
      <td><input id="username" name="username" type="text"></td>
    </tr>
    <tr>
      <td>���������룺</td>
      <td><input id="password" name="password" type="password"></td>
    </tr>
    <tr>
      <td colspan="2" align="center">
        <input type="submit" value="��¼">
      </td>
    </tr>
  </table>
</form>
</body>
</html>
