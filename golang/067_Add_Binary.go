package main

import "fmt"
import "bytes"

func binaryAdd(a byte, b byte , c byte, res *byte, carry *bool){
  var abc = a+b+c
  if abc == 0{
	*res=0
	*carry=false
  }else if abc == 1{
	*res=1
	*carry=false
  }else if abc == 2{
	*res=0
	*carry=true
  }else if abc == 3{
	*res=1
	*carry=true
  }
}

func addBinary(a string, b string) string {
  len_a := len(a)
  len_b := len(b)
  i := len_a-1
  j := len_b-1
  var res []string
  var x=a[0]
  fmt.Println(x)
  carry :=false
  var temp byte
  for ; i>= 0 && j >= 0; {		
	var a = byte(a[i]-'0')
	var b= byte(b[j]-'0')
	if carry{
	  binaryAdd(a, b, byte(1), &temp, &carry)
	}else{
	  binaryAdd(a, b, byte(0), &temp, &carry)
	}
	fmt.Println(a,b, temp, carry)
	res=append(res, string(temp+'0'))
	fmt.Println(a,b, temp, carry,res)
	i--
	j--
  }
  for;j >= 0; j--{
	if carry{
	  binaryAdd(byte(0), byte(b[j]-'0'), byte(1),&temp, &carry)	  
	}else{
	  binaryAdd(byte(0), byte(b[j]-'0'), byte(0),&temp, &carry)	  		
	}
	res=append(res, string(temp+'0'))
  }
  for;i >= 0; i--{
	if carry{
	  binaryAdd(byte(0), byte(a[i]-'0'), byte(1),&temp, &carry)	  
	  fmt.Println("!!!!!", temp,a[i])
	}else{
	  binaryAdd(byte(0), byte(a[i]-'0'), byte(0),&temp, &carry)	  		
	  fmt.Println("!!!!!", temp,a[i])
	}
	res=append(res, string(temp+'0'))
	fmt.Println(res, temp, i)
  }
  if carry{
	res=append(res, "1")
  }
  fmt.Println(res)
  var buffer bytes.Buffer
  for k:=len(res)-1; k>=0; k--{
	buffer.WriteString(res[k])
  }
  return buffer.String()
}


func main(){
  fmt.Println(addBinary("111111001", "1001") 	)
  fmt.Println("1"+"0")
  var a byte = 1
  var b byte = 1
  var c byte = 1
  fmt.Println(a+b+c)
}