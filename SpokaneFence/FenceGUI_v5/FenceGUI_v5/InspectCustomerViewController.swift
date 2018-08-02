//
//  InspectCustomerViewController.swift
//  FenceGUI_v5
//
//  Created by Tanner Orndorff on 7/31/18.
//  Copyright © 2018 Monocle Heads. All rights reserved.
//

import UIKit

class InspectCustomerViewController: UIViewController, UITableViewDelegate, UITableViewDataSource {
    @IBOutlet var estimateTable: UITableView!
    var cus: Customer?
    @IBOutlet var namedata: UILabel!
    @IBOutlet var addressdata: UILabel!
    @IBOutlet var emaildata: UILabel!
    @IBOutlet var phonenumdata: UILabel!
    @IBOutlet var notesdata: UITextView!
    @IBOutlet var loading: UIActivityIndicatorView?
    
    override func viewDidLoad() {
        super.viewDidLoad()
        self.estimateTable.dataSource = self
        self.estimateTable.delegate = self
        // Uncomment the following line to preserve selection between presentations
         //self.clearsSelectionOnViewWillAppear = false

        // Uncomment the following line to display an Edit button in the navigation bar for this view controller.
         //self.navigationItem.rightBarButtonItem = self.editButtonItem
         cus?.AddEstimate(id: 0, cid: "0", eid: "0", date: Date())
    }
    
    override func viewDidAppear(_ animated: Bool) {
        loading?.stopAnimating()
        namedata.text = (cus?.fname)! + " " + (cus?.lname)!
        addressdata.text = cus?.address
        emaildata.text = cus?.email
        phonenumdata.text = cus?.phone_num
        notesdata.text = cus?.notes
        
        
       
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }

    /*
    // MARK: - Navigation

    // In a storyboard-based application, you will often want to do a little preparation before navigation
    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        // Get the new view controller using segue.destinationViewController.
        // Pass the selected object to the new view controller.
    }
    */

    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return (cus?.estimates.count)!
    }
    
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let cell = tableView.dequeueReusableCell(withIdentifier: "estimatecell") as! estimatecell
        cell.est = cus?.estimates[indexPath.item]
        let formatter = DateFormatter()
        // initially set the format based on your datepicker date / server String
        formatter.dateFormat = "yyyy-MM-dd HH:mm:ss"
        let myString = formatter.string(from: Date()) // string purpose I add here
        // convert your string to date
        let yourDate = formatter.date(from: myString)
        //then again set the date format whhich type of output you need
        formatter.dateFormat = "dd-MMM-yyyy"
        // again convert your date to string
        let myStringafd = formatter.string(from: yourDate!)

        cell.textLabel?.text = "Estimate #\(indexPath.item+1)        Total Cost: $\(cell.est?.total_cost ?? 0)        Date: \(myStringafd)"
        return cell
    }
    func tableView(_ tableView: UITableView, commit editingStyle: UITableViewCellEditingStyle, forRowAt indexPath: IndexPath) {
        if (editingStyle == .delete){
            cus?.RemoveEstimate(key: indexPath.item)
            tableView.deleteRows(at: [indexPath], with: UITableViewRowAnimation.left)
            NSUserDefaultsManager.sychronize()
        }
    }
    
    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        if(segue.identifier == "editcustomer")
        {
            let editcustomer = segue.destination as! EditCustomerViewController
            editcustomer.cus = cus
        }
        if(segue.identifier == "addestimate")
        {
            let addestimate = segue.destination as! AddEstimateViewController
            addestimate.cus = cus
        }
    }
    
    @IBAction func unwindToInspect(for unwindSegue: UIStoryboardSegue) {
        let sourceVC = unwindSegue.source as! EditCustomerViewController
        sourceVC.cus = cus
    }

}
