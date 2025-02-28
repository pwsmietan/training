/*
 * cd /into working directory!!!
 *
 * go mod init golang.org/x/crypt/bcrypt
 * go mod tidy
 * go get golang.org/x/crypto/bcrypt
 */
package main

import (
	"fmt"

	"golang.org/x/crypto/bcrypt"
)

func HashPasswd(passwd string) (string, error) {
	// Cost for hashing has a direct impact on runtime performance, caveat emptor!
	bytes, err := bcrypt.GenerateFromPassword([]byte(passwd), bcrypt.MinCost)
	return string(bytes), err
}

func CheckPasswdHash(password, hash string) bool {
	err := bcrypt.CompareHashAndPassword([]byte(hash), []byte(password))
	return err == nil
}

func main() {
	plainPasswd := "MySuperSecretPassword12345"
	hash, _ := HashPasswd(plainPasswd)
	fmt.Printf("Passwd: %s\nHash: %s\n", plainPasswd, hash)
	fmt.Printf("Do the password and hash match? %v\n", CheckPasswdHash(plainPasswd, hash))

	plainPasswdSliceOfByte := []byte(plainPasswd)
	sliceOfByte, err := bcrypt.GenerateFromPassword(plainPasswdSliceOfByte, bcrypt.MinCost)
	if err != nil {
		fmt.Println(err)
	}

	fmt.Println(sliceOfByte)
}
