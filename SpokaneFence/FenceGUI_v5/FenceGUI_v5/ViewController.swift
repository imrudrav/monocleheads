//
//  ViewController.swift
//  FenceGUI_v5
//
//  Created by Tanner Orndorff on 7/7/18.
//  Copyright © 2018 Monocle Heads. All rights reserved.
//

import UIKit

class ViewController: UITableViewController {

    var spokaneFence = Business()
    var today = Date()
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
        //create a business or load an existing one
        spokaneFence.AddEmployee(fname: "Dave", lname: "Orndorff", email: "daveorndorff@comcast.net", phone_num: "5092300135", ssn: "123456789", address: "15109 E Belle Terre Ave Veradale WA 99037")
        spokaneFence.AddCustomer(fname: "Tanner", lname: "Secrest", address: "411 S 2060 W Vineyard UT 84058", email: "torndorff5@gmail.com", phone_num: 5096555446, notes: "Is really annoying and wont show us what hes got")
        spokaneFence.AddEstimate(cid: (spokaneFence.customerset.first?.key)!, eid: (spokaneFence.employeeset.first?.key)!, date: today)
        }
    

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }

    override func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return spokaneFence.estimateset.count
    }
    
    override func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> customcell {
        //need to get next object in list of estimates
        //set all custom cell properties to match estimate info
        //return cell
        let cell = tableView.dequeueReusableCell(withIdentifier: "customcell") as! customcell
        //get customer object
        let customer = spokaneFence.customerset[(spokaneFence.estimateset[indexPath.item]?.customer_id)!]
        
        cell.est = spokaneFence.estimateset[indexPath.item]
        cell.name = ((customer?.fname)! + (customer?.lname)!)
        cell.address = customer?.address
        cell.date = cell.est?.date
        cell.id = cell.est?.customer_id
        cell.textLabel?.text = cell.name
        return cell
    }
}

