//
//  ViewController.swift
//  FenceGUI_v5
//
//  Created by Tanner Orndorff on 7/7/18.
//  Copyright © 2018 Monocle Heads. All rights reserved.
//

import UIKit

class ViewController: UITableViewController {
    
    var today = Date()
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
        //create a business or load an existing one
        /*Business.AddEmployee(fname: "Dave", lname: "Orndorff", email: "daveorndorff@comcast.net", phone_num: "5092300135", ssn: "123456789", address: "15109 E Belle Terre Ave Veradale WA 99037")
        Business.AddCustomer(fname: "Tanner", lname: "Secrest", address: "411 S 2060 W Vineyard UT 84058", email: "torndorff5@gmail.com", phone_num: "5096555446", notes: "Is really annoying and wont show us what hes got")
        Business.AddCustomer(fname: "Luis", lname: "Montalvo", address: "12348 W Main Street, Airway Heights, Washington 99213", email: "lmontalvo@gmail.com", phone_num: "5092341254", notes: "Is really annoying and wont show us what hes got")
        Business.AddCustomer(fname: "Becca", lname: "Bangerz", address: "1234 Utah Valley Drive Provo UT 84058", email: "bbangerz69@hotmail.com", phone_num: "8012938443", notes: "Is really annoying and wont show us what hes got")
        Business.AddCustomer(fname: "Harry", lname: "Buthole", address: "9847 w Main Alpine UT 84058", email: "thebuthole@gmail.com", phone_num: "8019384353", notes: "Is really annoying and wont show us what hes got")
        Business.AddCustomer(fname: "Giancarlo", lname: "Stannnto", address: "Bronx NY", email: "GNYC5@gmail.com", phone_num: "5096555446", notes: "Is really annoying and wont show us what hes got")*/
        
       NSUserDefaultsManager.initializeDefaults()
        Business.updateID()
        
    }
    override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)
        tableView.reloadData()
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }

    override func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return Business.customers.count
    }
    
    override func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> customcell {
        //need to get next object in list of estimates
        //set all custom cell properties to match estimate info
        //return cell
        let cell = tableView.dequeueReusableCell(withIdentifier: "customcell") as! customcell
        //get customer object
        cell.cus = Business.customers[indexPath.item]
        cell.name = ((cell.cus?.fname)! + " " + (cell.cus?.lname)!)
        cell.address = cell.cus?.address
        cell.id = indexPath.item
        cell.textLabel?.text = cell.name! + "         " + cell.address! + "        " + (cell.cus?.phone_num)!
        cell.detailTextLabel?.text = cell.address
        return cell
    }
    
    override func tableView(_ tableView: UITableView, commit editingStyle: UITableViewCellEditingStyle, forRowAt indexPath: IndexPath) {
        if (editingStyle == .delete){
            Business.RemoveCustomer(key: indexPath.item)
            tableView.deleteRows(at: [indexPath], with: UITableViewRowAnimation.left)
             Business.updateID()
            NSUserDefaultsManager.sychronize()
        }
    }
    
    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        if(segue.identifier == "inspectcustomer")
        {
            let cell = sender as! customcell
            let inspectcustomer = segue.destination as! InspectCustomerViewController
            inspectcustomer.cus = cell.cus
        }
    }
}

