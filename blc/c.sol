// SPDX-License-Identifier: GPL-3.0

pragma solidity >=0.7.0 <0.9.0;

import "hardhat/console.sol";

contract MS {
    struct Student {
        int256 ID;
        string name;
        int256 marks;
    }

    int256 public stdCount = 0;
    Student[] public student_details;

    function addNewRecord(int256 ID, string memory name, int256 marks) public{
        stdCount += 1;

        Student memory s1 = Student(ID, name, marks);

        student_details.push(s1);
    }

    fallback() external{
        console.log("Fallback function called");
    }
}